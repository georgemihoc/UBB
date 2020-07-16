using System;
using System.Data;

namespace tasks.repository
{
	public static class DBUtils
	{
		

		private static IDbConnection instance = null;

		public static IDbConnection getConnection()
		{
			if (instance == null || instance.State == System.Data.ConnectionState.Closed)
			{
				instance = getNewConnection();
				instance.Open();
			}
			return instance;
		}

		private static IDbConnection getNewConnection()
		{
			
			return ConnectionUtils.ConnectionFactory.getInstance().createConnection();


		}
	}
}
