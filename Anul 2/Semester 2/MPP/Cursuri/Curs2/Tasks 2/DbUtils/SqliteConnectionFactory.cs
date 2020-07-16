using System;
using System.Data;
using Mono.Data.Sqlite;
namespace ConnectionUtils
{
	public class SqliteConnectionFactory : ConnectionFactory
	{
		public override IDbConnection createConnection()
		{
			//Mono Sqlite Connection
			String connectionString = "URI=file:/Users/george/Documents/UBB/Anul 2/Semester 2/MPP/Cursuri/Curs2/Tasks 2/DbUtils/C#Db,Version=3";
			return new SqliteConnection(connectionString);

			// Windows Sqlite Connection, fisierul .db ar trebuie sa fie in directorul debug/bin
			//String connectionString = "Data Source=tasks.db;Version=3";
			//return new SqliteConnection(connectionString);
		}
	}
}
