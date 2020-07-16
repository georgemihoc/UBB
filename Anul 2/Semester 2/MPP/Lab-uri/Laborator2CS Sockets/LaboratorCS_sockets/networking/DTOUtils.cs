namespace swim.network.dto
{

	using Organizator = swim.model.Organizator;
	using Inscriere = swim.model.Inscriere;
    using swim.model;

    public class DTOUtils
	{
		public static Organizator getFromDTO(UserDTO usdto)
		{
			string id =usdto.Id;
			string pass =usdto.Passwd;
			return new Organizator(1,id, pass);

		}
		public static UserDTO getDTO(Organizator user)
		{
			string id =user.Username;
			string pass =user.Password;
			return new UserDTO(id, pass);
		}
		

		public static Inscriere getFromDTO(InscriereDTO mdto)
		{
			int idInscriere = mdto.IdInscriere;
			int idParticipant = mdto.IdParticipant;
			int idProba = mdto.IdProba;
			return new Inscriere(idInscriere,idParticipant,idProba);
		}

		public static InscriereDTO getDTO(Inscriere inscriere,string nume, int varsta)
		{
			int idInscriere = inscriere.IdInscriere;
			int idParticipant = inscriere.IdParticipant;
			int idProba = inscriere.IdProba;
			return new InscriereDTO(idInscriere, idParticipant, idProba,nume,varsta);
		}

		public static UserDTO[] getDTO(Organizator[] users)
		{
			UserDTO[] frDTO = new UserDTO[users.Length];
			for (int i = 0; i < users.Length; i++)
			{
				frDTO[i] = getDTO(users[i]);
			}
			return frDTO;
		}

		public static Organizator[] getFromDTO(UserDTO[] users)
		{
			Organizator[] friends = new Organizator[users.Length];
			for (int i = 0; i < users.Length; i++)
			{
				friends[i] = getFromDTO(users[i]);
			}
			return friends;
		}
		/// <summary>
		/// Pentru Proba
		/// </summary>
		/// <param name="usdto"></param>
		/// <returns></returns>
		public static Proba getFromDTO(ProbaDTO usdto)
		{
			
			return new Proba(usdto.IdProba, usdto.Lungime, usdto.Stil,usdto.NrParticipanti);

		}
		public static ProbaDTO getDTO(Proba proba)
		{
			return new ProbaDTO(proba.IdProba, proba.Lungime, proba.Stil, proba.NrParticipanti);
		}

		public static Proba[] getFromDTO(ProbaDTO[] probe)
		{
			Proba[] friends = new Proba[probe.Length];
			for (int i = 0; i < probe.Length; i++)
			{
				friends[i] = getFromDTO(probe[i]);
			}
			return friends;
		}
		public static ProbaDTO[] getDTO(Proba[] users)
		{
			ProbaDTO[] frDTO = new ProbaDTO[users.Length];
			for (int i = 0; i < users.Length; i++)
			{
				frDTO[i] = getDTO(users[i]);
			}
			return frDTO;
		}

		/// <summary>
		/// Pentru Participant
		/// </summary>
		/// <param name="usdto"></param>
		/// <returns></returns>
		public static Participant getFromDTO(ParticipantDTO usdto)
		{

			return new Participant(usdto.IdParticipant, usdto.Nume, usdto.Varsta);

		}
		public static ParticipantDTO getDTO(Participant participant)
		{
			return new ParticipantDTO(participant.IdParticipant, participant.Nume, participant.Varsta);
		}

		public static Participant[] getFromDTO(ParticipantDTO[] participanti)
		{
			Participant[] friends = new Participant[participanti.Length];
			for (int i = 0; i < participanti.Length; i++)
			{
				friends[i] = getFromDTO(participanti[i]);
			}
			return friends;
		}
		public static ParticipantDTO[] getDTO(Participant[] users)
		{
			ParticipantDTO[] frDTO = new ParticipantDTO[users.Length];
			for (int i = 0; i < users.Length; i++)
			{
				frDTO[i] = getDTO(users[i]);
			}
			return frDTO;
		}

		/// <summary>
		/// Pentru inscriere getter
		/// </summary>
		/// <param name="usdto"></param>
		/// <returns></returns>

		public static Inscriere getFromDTO(InscriereDTO2 usdto)
		{

			return new Inscriere(usdto.IdInscriere, usdto.IdParticipant, usdto.IdProba);

		}
		public static InscriereDTO2 getDTO(Inscriere inscriere)
		{
			return new InscriereDTO2(inscriere.IdInscriere,inscriere.IdParticipant,inscriere.IdProba);
		}

		public static Inscriere[] getFromDTO(InscriereDTO2[] inscrieri)
		{
			Inscriere[] friends = new Inscriere[inscrieri.Length];
			for (int i = 0; i < inscrieri.Length; i++)
			{
				friends[i] = getFromDTO(inscrieri[i]);
			}
			return friends;
		}
		public static InscriereDTO2[] getDTO(Inscriere[] users)
		{
			InscriereDTO2[] frDTO = new InscriereDTO2[users.Length];
			for (int i = 0; i < users.Length; i++)
			{
				frDTO[i] = getDTO(users[i]);
			}
			return frDTO;
		}




	}
}