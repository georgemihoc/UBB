using System;

namespace swim.network.dto
{


	///
	/// <summary> * Created by IntelliJ IDEA.
	/// * User: grigo
	/// * Date: Mar 18, 2009
	/// * Time: 4:22:15 PM </summary>
	/// 
	[Serializable]
	public class InscriereDTO
	{
		private	int idInscriere;
		private int idParticipant;
		private int idProba;
		private string nume;
		private int varsta;

		public InscriereDTO(int idInscriere, int idParticipant, int idProba, string nume, int varsta)
		{
			this.idInscriere = idInscriere;
			this.idParticipant = idParticipant;
			this.idProba = idProba;
			this.nume = nume;
			this.varsta = varsta;
		}

		public int IdInscriere
		{
			get => idInscriere;
			set => idInscriere = value;
		}
		public int IdParticipant
		{
			get => idParticipant;
			set => idParticipant = value;
		}
		public int IdProba
		{
			get => idProba;
			set => idProba = value;
		}
		public string Nume
		{
			get => nume;
			set => nume = value;
		}
		public int Varsta
		{
			get => varsta;
			set => varsta = value;
		}

	}

}