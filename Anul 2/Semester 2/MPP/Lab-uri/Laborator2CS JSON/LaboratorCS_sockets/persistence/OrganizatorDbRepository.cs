using System;
// using tasks.model;
using System.Collections.Generic;
using System.Data;
using log4net;
using swim.model;

namespace swim.persistence
{
	public class OrganizatorDbRepository: IRepository<int,Organizator>
	{
		private static readonly ILog log = LogManager.GetLogger("OrganizatorDbRepository");
		public OrganizatorDbRepository()
		{
			log.Info("Creating OrganizatorDbRepository");
		}

		public Organizator findOne(int id)
		{
			log.InfoFormat("Entering findOne with value {0}", id);
			IDbConnection con = DBUtils.getConnection();

			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "select idOrganizator,username, password from Organizator where idOrganizator=@id";
				IDbDataParameter paramId = comm.CreateParameter();
				paramId.ParameterName = "@id";
				paramId.Value = id;
				comm.Parameters.Add(paramId);

				using (var dataR = comm.ExecuteReader())
				{
					if (dataR.Read())
					{
						int idOrganizator = dataR.GetInt32(0);
						String username = dataR.GetString(1);
						String password = dataR.GetString(2);
						Organizator Organizator = new Organizator(idOrganizator, username, password);
						log.InfoFormat("Exiting findOne with value {0}", Organizator);
						return Organizator;
					}
				}
			}
			log.InfoFormat("Exiting findOne with value {0}", null);
			return null;
		}

		public IEnumerable<Organizator> findAll()
		{
			IDbConnection con = DBUtils.getConnection();
			IList<Organizator> tasksR = new List<Organizator>();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "select idOrganizator,username, password from Organizator";

				using (var dataR = comm.ExecuteReader())
				{
					while (dataR.Read())
					{
						int idOrganizator = dataR.GetInt32(0);
						String username = dataR.GetString(1);
						String password = dataR.GetString(2);
						Organizator Organizator = new Organizator(idOrganizator, username, password);
						tasksR.Add(Organizator);
					}
				}
			}

			return tasksR;
		}
		public void save(Organizator entity)
		{
			var con = DBUtils.getConnection();

			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "insert into Organizator  values (@idOrganizator, @username, @password)";
				var paramId = comm.CreateParameter();
				paramId.ParameterName = "@idOrganizator";
				paramId.Value = entity.IdOrganizator;
				comm.Parameters.Add(paramId);

				var paramUsername = comm.CreateParameter();
				paramUsername.ParameterName = "@username";
				paramUsername.Value = entity.Username;
				comm.Parameters.Add(paramUsername);

				var paramPassword = comm.CreateParameter();
				paramPassword.ParameterName = "@varsta";
				paramPassword.Value = entity.Password;
				comm.Parameters.Add(paramPassword);
				
				var result = comm.ExecuteNonQuery();
				if (result == 0)
					throw new RepositoryException("No elem added !");
			}
			
		}
		public void delete(int idOrganizator)
		{
			IDbConnection con = DBUtils.getConnection();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "delete from Organizator where idOrganizator=@idOrgranizator";
				IDbDataParameter paramId = comm.CreateParameter();
				paramId.ParameterName = "@idOrganizator";
				paramId.Value = idOrganizator;
				comm.Parameters.Add(paramId);
				var dataR = comm.ExecuteNonQuery();
				if (dataR == 0)
					throw new RepositoryException("No elem deleted!");
			}
		}

		public void update(int id, Organizator entity)
		{
			throw new NotImplementedException();
		}
	}
}
