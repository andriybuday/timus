using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
// NOTE: Requires Html Agility Pack https://htmlagilitypack.codeplex.com/
using HtmlAgilityPack;

namespace LoadTimusSolutions
{
    public class AcceptedSolution
    {
        public string SubmitFile { get; set; }
        public int SubmitNumber { get; set; }
        public string DateString { get; set; }
        public string ProblemNumber { get; set; }
    }

    class TimusSolutionsExporter
    {
        const string URL_SUBMISSIONS = "http://acm.timus.ru/status.aspx?author=YOUR_AUTHOR_ID&status=accepted&count=600";
        const string POST_DATA = "Action=getsubmit&JudgeID=YOUR_JUDGE_ID&Password=PASSWORD_ENCODED";
        const string FILE_LOCATION_AND_FORMAT = @"d:\Projects\TimusExport\{0}_{1}_{2}";

        static void Main(string[] args)
        {
            new TimusSolutionsExporter().Run();
        }

        private void Run()
        {
            Console.WriteLine("acm.timus.ru exporter...");
            var allAcceptedSolutions = GetAllAcceptedSolutions();
            foreach (var acceptedSolution in allAcceptedSolutions)
            {
                DownloadSubmissionAndSaveToFile(acceptedSolution);
            }
        }

        private static List<AcceptedSolution> GetAllAcceptedSolutions()
        {
            var request = (HttpWebRequest)WebRequest.Create(URL_SUBMISSIONS);
            request.Method = "GET";
            var html = ReadResponseToEnd(request);

            var doc = new HtmlDocument();
            doc.LoadHtml(html);

            var nodesMatchingXPath = doc.DocumentNode.SelectNodes("html/body/table/tr/td/table/tr");

            var acceptedSolutions = new List<AcceptedSolution>();
            foreach (var row in nodesMatchingXPath)
            {
                var aHrefCollection = row.SelectNodes("td/a");
                var hrefs = aHrefCollection?.ToList();
                var nobr = row.SelectNodes("td/nobr")?.LastOrDefault();
                if (hrefs != null && hrefs.Count >= 0)
                {
                    var ac = new AcceptedSolution();
                    foreach (var href in hrefs)
                    {
                        var hrefValue = href.GetAttributeValue("href", "");
                        if (hrefValue.Contains("getsubmit"))
                        {
                            ac.SubmitFile = hrefValue.Split('/').LastOrDefault();
                            if (ac.SubmitFile != null)
                            {
                                int number;
                                int.TryParse(ac.SubmitFile.Split('.').First(), out number);
                                ac.SubmitNumber = number;
                            }
                        }
                        if (hrefValue.Contains("problem"))
                        {
                            ac.ProblemNumber = hrefValue
                                .Split(new[] { "num=" }, StringSplitOptions.None).LastOrDefault();
                        }
                    }
                    ac.DateString = nobr != null ? nobr.InnerText : "";
                    acceptedSolutions.Add(ac);
                }
            }

            var oneAcPerProblem = acceptedSolutions
                // all valid
                .Where(ac => ac.ProblemNumber != null && ac.SubmitFile != null)
                // grouped by problem number
                .GroupBy(ac => ac.ProblemNumber)
                // one latest submission per problem number
                .Select(acGroup => acGroup.OrderByDescending(ac => ac.SubmitNumber).First())
                .ToList();

            return oneAcPerProblem;
        }

        private static void DownloadSubmissionAndSaveToFile(AcceptedSolution accSolution)
        {
            var encoding = new ASCIIEncoding();
            var data = encoding.GetBytes(POST_DATA);

            var url = $"http://acm.timus.ru/getsubmit.aspx/{accSolution.SubmitFile}";
            var request = (HttpWebRequest)WebRequest.Create(url);
            request.Method = "POST";
            request.ContentType = "application/x-www-form-urlencoded";
            request.ContentLength = data.Length;
            var newStream = request.GetRequestStream();
            newStream.Write(data, 0, data.Length);
            newStream.Close();

            var solutionFileContent = ReadResponseToEnd(request);

            var filePath = string.Format(FILE_LOCATION_AND_FORMAT, accSolution.ProblemNumber,
                accSolution.DateString.Replace(" ", ""), accSolution.SubmitFile);

            File.WriteAllText(filePath, solutionFileContent);
            Console.WriteLine(filePath);
        }

        private static string ReadResponseToEnd(HttpWebRequest request)
        {
            var response = request.GetResponse();
            var responseStream = response.GetResponseStream();
            var responseReader = new StreamReader(responseStream);
            return responseReader.ReadToEnd();
        }
    }
}
