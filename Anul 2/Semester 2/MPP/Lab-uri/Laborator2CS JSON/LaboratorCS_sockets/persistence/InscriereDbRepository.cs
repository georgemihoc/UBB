using log4net;
using swim.model;
using System;
using System.Collections.Generic;
using System.Data;


namespace swim.persistence
{
	public class InscriereDbRepository: IRepository<int,Inscriere>
	{
		private static readonly ILog log = LogManager.GetLogger("InscriereDbRepository");
		public InscriereDbRepository()
		{
			log.Info("Creating InscriereDbRepository");
		}

		public Inscriere findOne(int id)
		{
			log.InfoFormat("Entering findOne with value {0}", id);
			IDbConnection con = DBUtils.getConnection();

			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "select idInscriere,idParticipant, idProba from Inscriere where idInscriere=@id";
				IDbDataParameter paramId = comm.CreateParameter();
				paramId.ParameterName = "@id";
				paramId.Value = id;
				comm.Parameters.Add(paramId);

				using (var dataR = comm.ExecuteReader())
				{
					if (dataR.Read())
					{
						int idInscriere = dataR.GetInt32(0);
						int idParticipant = dataR.GetInt32(1);
						int idProba = dataR.GetInt32(2);
						
						Inscriere Inscriere = new Inscriere(idInscriere, idParticipant, idProba);
						log.InfoFormat("Exiting findOne with value {0}", Inscriere);
						return Inscriere;
					}
				}
			}
			log.InfoFormat("Exiting findOne with value {0}", null);
			return null;
		}

		public IEnumerable<Inscriere> findAll()
		{
			IDbConnection con = DBUtils.getConnection();
			IList<Inscriere> tasksR = new List<Inscriere>();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "select idInscriere,idParticipant, idProba from Inscriere";

				using (var dataR = comm.ExecuteReader())
				{
					while (dataR.Read())
					{
						int idInscriere = dataR.GetInt32(0);
						int idParticipant = dataR.GetInt32(1);
						int idProba = dataR.GetInt32(2);
						
						Inscriere Inscriere = new Inscriere(idInscriere, idParticipant, idProba);
						tasksR.Add(Inscriere);
					}
				}
			}

			return tasksR;
		}
		public void save(Inscriere entity)
		{
			var con = DBUtils.getConnection();

			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "insert into Inscriere  values (@idInscriere, @idParticipant, @idProba)";
				var paramId = comm.CreateParameter();
				paramId.ParameterName = "@idInscriere";
				paramId.Value = entity.IdInscriere;
				comm.Parameters.Add(paramId);

				var paramIdParticipant = comm.CreateParameter();
				paramIdParticipant.ParameterName = "@idParticipant";
				paramIdParticipant.Value = entity.IdParticipant;
				comm.Parameters.Add(paramIdParticipant);

				var paramIdProba = comm.CreateParameter();
				paramIdProba.ParameterName = "@idProba";
				paramIdProba.Value = entity.IdProba;
				comm.Parameters.Add(paramIdProba);
				
				var result = comm.ExecuteNonQuery();
				if (result == 0)
					throw new RepositoryException("No element added !");
			}
			
		}
		public void delete(int idInscriere)
		{
			IDbConnection con = DBUtils.getConnection();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "delete from Inscriere where idInscriere=@idInscriere";
				IDbDataParameter paramId = comm.CreateParameter();
				paramId.ParameterName = "@idInscriere";
				paramId.Value = idInscriere;
				comm.Parameters.Add(paramId);
				var dataR = comm.ExecuteNonQuery();
				if (dataR == 0)
					throw new RepositoryException("No element deleted!");
			}
		}

		public void update(int id, Inscriere entity)
		{
			throw new NotImplementedException();
		}
	}
}
