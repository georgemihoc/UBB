using System;
// using tasks.model;
using System.Collections.Generic;
using System.Data;
using log4net;
using swim.model;

namespace swim.persistence
{
	public class ParticipantDbRepository: IRepository<int,Participant>
	{
		private static readonly ILog log = LogManager.GetLogger("ParticipantDbRepository");
		public ParticipantDbRepository()
		{
			log.Info("Creating ParticipantDbRepository");
		}

		public Participant findOne(int id)
		{
			log.InfoFormat("Entering findOne with value {0}", id);
			IDbConnection con = DBUtils.getConnection();

			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "select idParticipant,nume, varsta from Participant where idParticipant=@id";
				IDbDataParameter paramId = comm.CreateParameter();
				paramId.ParameterName = "@id";
				paramId.Value = id;
				comm.Parameters.Add(paramId);

				using (var dataR = comm.ExecuteReader())
				{
					if (dataR.Read())
					{
						int idParticipant = dataR.GetInt32(0);
						String nume = dataR.GetString(1);
						int varsta = dataR.GetInt32(2);
						Participant participant = new Participant(idParticipant, nume, varsta);
						log.InfoFormat("Exiting findOne with value {0}", participant);
						return participant;
					}
				}
			}
			log.InfoFormat("Exiting findOne with value {0}", null);
			return null;
		}

		public IEnumerable<Participant> findAll()
		{
			IDbConnection con = DBUtils.getConnection();
			IList<Participant> tasksR = new List<Participant>();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "select idParticipant,nume, varsta from Participant";

				using (var dataR = comm.ExecuteReader())
				{
					while (dataR.Read())
					{
						int idParticipant = dataR.GetInt32(0);
						String nume = dataR.GetString(1);
						int varsta = dataR.GetInt32(2);
						Participant participant = new Participant(idParticipant, nume, varsta);
						tasksR.Add(participant);
					}
				}
			}

			return tasksR;
		}
		public void save(Participant entity)
		{
			var con = DBUtils.getConnection();

			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "insert into Participant  values (@idParticipant, @nume, @varsta)";
				var paramId = comm.CreateParameter();
				paramId.ParameterName = "@idParticipant";
				paramId.Value = entity.IdParticipant;
				comm.Parameters.Add(paramId);

				var paramNume = comm.CreateParameter();
				paramNume.ParameterName = "@nume";
				paramNume.Value = entity.Nume;
				comm.Parameters.Add(paramNume);

				var paramVarsta = comm.CreateParameter();
				paramVarsta.ParameterName = "@varsta";
				paramVarsta.Value = entity.Varsta;
				comm.Parameters.Add(paramVarsta);
				
				var result = comm.ExecuteNonQuery();
				if (result == 0)
					throw new RepositoryException("No elem added !");
			}
			
		}
		public void delete(int idParticipant)
		{
			IDbConnection con = DBUtils.getConnection();
			using (var comm = con.CreateCommand())
			{
				comm.CommandText = "delete from Participant where idParticipant=@idParticipant";
				IDbDataParameter paramId = comm.CreateParameter();
				paramId.ParameterName = "@idParticipant";
				paramId.Value = idParticipant;
				comm.Parameters.Add(paramId);
				var dataR = comm.ExecuteNonQuery();
				if (dataR == 0)
					throw new RepositoryException("No elem deleted!");
			}
		}

		public void update(int id, Participant entity)
		{
			throw new NotImplementedException();
		}
	}
}
