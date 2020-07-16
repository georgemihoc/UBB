using System;
// using tasks.model;
using System.Collections.Generic;
using System.Data;
using log4net;
using swim.model;

namespace swim.persistence
{
	public class ProbaDbRepository: IRepository<int,Proba>
	{
		private static readonly ILog log = LogManager.GetLogger("ProbaDbRepository");
		public ProbaDbRepository()
		{
			log.Info("Creating ProbaDbRepository");
		}

		public Proba findOne(int id)
		{
			log.InfoFormat("Entering findOne with value {0}", id);
			IDbConnection con = DBUtils.getConnection();

			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "select idProba,lungime, stil, nrParticipanti from Proba where idProba=@id";
				IDbDataParameter paramId = comm.CreateParameter();
				paramId.ParameterName = "@id";
				paramId.Value = id;
				comm.Parameters.Add(paramId);

				using (var dataR = comm.ExecuteReader())
				{
					if (dataR.Read())
					{
						int idProba = dataR.GetInt32(0);
						int lungime = dataR.GetInt32(1);
						String stil = dataR.GetString(2);
						int nrParticipanti = dataR.GetInt32(3);


						Proba Proba = new Proba(idProba, lungime, stil,nrParticipanti);
						log.InfoFormat("Exiting findOne with value {0}", Proba);
						return Proba;
					}
				}
			}
			log.InfoFormat("Exiting findOne with value {0}", null);
			return null;
		}

		public IEnumerable<Proba> findAll()
		{
			IDbConnection con = DBUtils.getConnection();
			IList<Proba> tasksR = new List<Proba>();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "select idProba,lungime,stil,nrParticipanti from Proba";

				using (var dataR = comm.ExecuteReader())
				{
					while (dataR.Read())
					{
						int idProba = dataR.GetInt32(0);
						int lungime = dataR.GetInt32(1);
						String stil = dataR.GetString(2);
						int nrParticipanti = dataR.GetInt32(3);


						Proba Proba = new Proba(idProba, lungime, stil,nrParticipanti);
						tasksR.Add(Proba);
					}
				}
			}

			return tasksR;
		}
		public void save(Proba entity)
		{
			var con = DBUtils.getConnection();

			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "insert into Proba  values (@idProba, @lungime, @stil, @nrParticipanti)";
				var paramId = comm.CreateParameter();
				paramId.ParameterName = "@idProba";
				paramId.Value = entity.IdProba;
				comm.Parameters.Add(paramId);

				var paramLungime = comm.CreateParameter();
				paramLungime.ParameterName = "@lungime";
				paramLungime.Value = entity.Lungime;
				comm.Parameters.Add(paramLungime);

				var paramStil = comm.CreateParameter();
				paramStil.ParameterName = "@stil";
				paramStil.Value = entity.Stil;
				comm.Parameters.Add(paramStil);
				
				var paramNrParticipanti = comm.CreateParameter();
				paramNrParticipanti.ParameterName = "@nrParticipanti";
				paramNrParticipanti.Value = entity.NrParticipanti;
				comm.Parameters.Add(paramNrParticipanti);
				
				var result = comm.ExecuteNonQuery();
				if (result == 0)
					throw new RepositoryException("No element added !");
			}
			
		}
		public void update(int idProba, Proba proba)
		{
			IDbConnection con = DBUtils.getConnection();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "update Proba set idProba = @id , lungime = @lungime, stil = @stil, nrParticipanti=@nrParticipanti where idProba=@id";
				var paramId = comm.CreateParameter();
				paramId.ParameterName = "@id";
				paramId.Value = idProba;
				comm.Parameters.Add(paramId);

				var paramLungime = comm.CreateParameter();
				paramLungime.ParameterName = "@lungime";
				paramLungime.Value = proba.Lungime;
				comm.Parameters.Add(paramLungime);

				var paramStil = comm.CreateParameter();
				paramStil.ParameterName = "@stil";
				paramStil.Value = proba.Stil;
				comm.Parameters.Add(paramStil);

				var paramNrParticipanti = comm.CreateParameter();
				paramNrParticipanti.ParameterName = "@nrParticipanti";
				paramNrParticipanti.Value = proba.NrParticipanti;
				comm.Parameters.Add(paramNrParticipanti);
				var dataR = comm.ExecuteNonQuery();
				if (dataR == 0)
					throw new RepositoryException("No element deleted!");
			}
		}

		public void delete(int idProba)
		{
			IDbConnection con = DBUtils.getConnection();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "delete from Proba where idProba=@idProba";
				IDbDataParameter paramId = comm.CreateParameter();
				paramId.ParameterName = "@id";
				paramId.Value = idProba;
				comm.Parameters.Add(paramId);
				var dataR = comm.ExecuteNonQuery();
				if (dataR == 0)
					throw new RepositoryException("No element deleted!");
			}
		}
		
	}
}
