using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Serialization;

namespace CSharpRestClient
{
	class MainClass
	{
		static HttpClient client = new HttpClient();

		public static void Main(string[] args)
		{
			RunAsync().Wait();
		}

		static async Task RunAsync()
		{
			client.BaseAddress = new Uri("http://localhost:8080/swim/probe");
			client.DefaultRequestHeaders.Accept.Clear();
			client.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
			
			// Get Proba by ID
			Console.WriteLine("Get proba with idProba =  8");
			Proba result = await GetProbaAsync("http://localhost:8080/swim/probe/"+ 8);
			Console.WriteLine("Received {0}", result);
			
			// Get All Probe
			Console.WriteLine();
			Console.WriteLine("All Probe");
			List<Proba> result3 = await GetProbeAsync("http://localhost:8080/swim/probe/");
			foreach (var proba in result3)
			{
				Console.WriteLine(proba);
			}

			// AddProba();
			// UpdateProba();
			// DeleteProba();
		}


		static async void AddProba()
		{
			Proba proba = new Proba(9,100,"stil",100);
			var json = JsonConvert.SerializeObject(proba, new JsonSerializerSettings { ContractResolver = new CamelCasePropertyNamesContractResolver() });
			Console.WriteLine("Saving ..."+ json);
			var data = new StringContent(json, Encoding.UTF8, "application/json");

			var url = "http://localhost:8080/swim/probe";

			var response = await client.PostAsync(url, data);

			string result2 = response.Content.ReadAsStringAsync().Result;
		}
		static async void UpdateProba()
		{
			Proba proba = new Proba(9,100,"stil",250);
			var json = JsonConvert.SerializeObject(proba, new JsonSerializerSettings { ContractResolver = new CamelCasePropertyNamesContractResolver() });
			Console.WriteLine("Updating ..."+ json);
			var data = new StringContent(json, Encoding.UTF8, "application/json");

			var url = "http://localhost:8080/swim/probe/9";

			var response = await client.PutAsync(url, data);

			string result2 = response.Content.ReadAsStringAsync().Result;
		}
		static async void DeleteProba()
		{
			var url = "http://localhost:8080/swim/probe/9";
			Console.WriteLine("Deleting proba 9 ...");

			var response = await client.DeleteAsync(url);

			string result2 = response.Content.ReadAsStringAsync().Result;
		}

		static async Task<Proba> GetProbaAsync(string path)
		{
			Proba proba = null;
			HttpResponseMessage response = await client.GetAsync(path);
			if (response.IsSuccessStatusCode)
			{
				proba = await response.Content.ReadAsAsync<Proba>();
			}
			return proba;
		}
		
		static async Task<List<Proba>> GetProbeAsync(string path)
		{
			List<Proba> probe = null;
			HttpResponseMessage response = await client.GetAsync(path);
			if (response.IsSuccessStatusCode)
			{
				probe = await response.Content.ReadAsAsync<List<Proba>>();
			}
			return probe;
		}
	}
	public class Proba
	{
		public int IdProba { get; set; }
		public int Lungime  { get; set; }
		public string Stil { get; set; }
		public int NrParticipanti  { get; set; }

		public Proba(int idProba, int lungime, string stil, int nrParticipanti)
		{
			IdProba = idProba;
			Lungime = lungime;
			Stil = stil;
			NrParticipanti = nrParticipanti;
		}


		public override string ToString()
		{
			return string.Format("[Proba: IdProba={0}, Lungime={1}, Stil={2}, NrParticipanti={3}]", IdProba, Lungime, Stil, NrParticipanti);
		}
	}
	
}
