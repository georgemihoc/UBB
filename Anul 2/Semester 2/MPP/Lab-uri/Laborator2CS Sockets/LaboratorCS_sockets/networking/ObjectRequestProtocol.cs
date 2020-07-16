using System;
namespace swim.network.protocol
{
	using UserDTO = swim.network.dto.UserDTO;
	using InscriereDTO = swim.network.dto.InscriereDTO;


	public interface Request 
	{
	}


	[Serializable]
	public class LoginRequest : Request
	{
		private UserDTO user;

		public LoginRequest(UserDTO user)
		{
			this.user = user;
		}

		public virtual UserDTO User
		{
			get
			{
				return user;
			}
		}
	}


	[Serializable]
	public class AddParticipantRequest : Request
	{
		private InscriereDTO inscriere;

		public AddParticipantRequest(InscriereDTO inscriere)
		{
			this.inscriere = inscriere;
		}

		public virtual InscriereDTO InscriereDto
		{
			get
			{
				return inscriere;
			}
		}
	}

	[Serializable]
	public class GetLoggedFriendsRequest : Request
	{
		private UserDTO user;

		public GetLoggedFriendsRequest(UserDTO user)
		{
			this.user = user;
		}

		public virtual UserDTO User
		{
			get
			{
				return user;
			}
		}
	}
	[Serializable]
	public class GetProbeRequest : Request
	{
		private UserDTO user;

		public GetProbeRequest(UserDTO user)
		{
			this.user = user;
		}

		public virtual UserDTO User
		{
			get
			{
				return user;
			}
		}
	}
	[Serializable]
	public class GetParticipantiRequest : Request
	{
		private UserDTO user;

		public GetParticipantiRequest(UserDTO user)
		{
			this.user = user;
		}

		public virtual UserDTO User
		{
			get
			{
				return user;
			}
		}
	}
	[Serializable]
	public class GetInscrieriRequest : Request
	{
		private UserDTO user;

		public GetInscrieriRequest(UserDTO user)
		{
			this.user = user;
		}

		public virtual UserDTO User
		{
			get
			{
				return user;
			}
		}
	}

	//[Serializable]
	//public class GetProbe : Request
	//{
	//	private GetProbe()
	//}


}