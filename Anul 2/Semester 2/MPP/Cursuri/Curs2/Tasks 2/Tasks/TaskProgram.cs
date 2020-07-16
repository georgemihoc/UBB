using System;
using tasks.model;
using tasks.utils;
using tasks.runner;
using tasks.repository;
using log4net;
using log4net.Config;
namespace Sem10
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			//Console.WriteLine ("Hello World!");
			XmlConfigurator.Configure(new System.IO.FileInfo(args[0]));

			Console.WriteLine("Sorting Tasks Repository DB ...");
			SortingTaskDbRepository repo = new SortingTaskDbRepository();

			Console.WriteLine("Taskurile din db");
			foreach (SortingTask t in repo.findAll())
			{
				Console.WriteLine(t);
			}
			// SortingTask task = repo.findOne(4);
			// repo.delete(4);
			// task.Description = "Ana are mere";
			// repo.save(task);
			//
			// Console.WriteLine("Taskurile din db dupa stergere/adaugare");
			// foreach (SortingTask t in repo.findAll())
			// {
			// 	Console.WriteLine(t);
			// }


			
		}

	}
}
