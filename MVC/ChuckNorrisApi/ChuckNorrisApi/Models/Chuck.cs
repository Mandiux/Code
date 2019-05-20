using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using Newtonsoft.Json;

namespace ChuckNorrisApi.Models
{
    public class Chuck
    {
        string categoryEndPoint = "https://api.chucknorris.io/jokes/categories";
        public List<string> categoryList = new List<string>();
        public string defaultCategory = string.Empty;
        public string chuckJoke = string.Empty;

        public Chuck()
        {
            // Get Joke Categories.
            dynamic categories = JsonConvert.DeserializeObject(getChuckData(categoryEndPoint));
            
            foreach (var category in categories)
            {
                categoryList.Add(category.Value.ToUpper().ToString());
            }
        }


        public void getJoke()
        {
            const string RANDOM_ENDPOINT = "https://api.chucknorris.io/jokes/random";
            const string CATEGORY_ENDPOINT = "https://api.chucknorris.io/jokes/random?category={0}";

            if (defaultCategory != "Any Category")
            {
                dynamic joke = JsonConvert.DeserializeObject(getChuckData(String.Format(CATEGORY_ENDPOINT, defaultCategory)));
                chuckJoke =  joke.value.ToString();
            }
            else
            {
                dynamic joke = JsonConvert.DeserializeObject(getChuckData(RANDOM_ENDPOINT));
                chuckJoke = joke.value.Tostring();
            }
        }

        public string getChuckData(string endPoint)
        {
            // Create a request for the URL. 		
            WebRequest request = WebRequest.Create(endPoint);
            // If required by the server, set the credentials.
            request.Credentials = CredentialCache.DefaultCredentials;
            // Get the response.
            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            // Get the stream containing content returned by the server.
            Stream dataStream = response.GetResponseStream();
            // Open the stream using a StreamReader for easy access.
            StreamReader reader = new StreamReader(dataStream);
            // Read the content.
            string responseFromServer = reader.ReadToEnd();
            
            // Close.
            reader.Close();
            dataStream.Close();
            response.Close();

            // Return data.
            return responseFromServer;
        }
    }

 
}


