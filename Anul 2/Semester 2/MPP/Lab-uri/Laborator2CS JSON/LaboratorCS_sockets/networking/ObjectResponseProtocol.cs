using swim.network.dto;
using System;
using System.Collections.Generic;
using swim.model;

namespace swim.network.protocol
{
	using UserDTO = swim.network.dto.UserDTO;
	using InscriereDTO = swim.network.dto.InscriereDTO;

	public interface Response 
	{
	}

	[Serializable]
	public class OkResponse : Response
	{
		
	}

    [Serializable]
	public class ErrorResponse : Response
	{
		private string message;

		public ErrorResponse(string message)
		{
			this.message = message;
		}

		public virtual string Message
		{
			get
			{
				return message;
			}
		}
	}

	[Serializable]
	public class GetLoggedFriendsResponse : Response
	{
		private UserDTO[] friends;

		public GetLoggedFriendsResponse(UserDTO[] friends)
		{
			this.friends = friends;
		}

		public virtual UserDTO[] Friends
		{
			get
			{
				return friends;
			}
		}
	}

	[Serializable]
	public class GetProbeResponse : Response
	{
		private List<String> probe;

		public GetProbeResponse(List<String> friends)
		{
			this.probe = friends;
		}

		public virtual List<String> Probe
		{
			get
			{
				return probe;
			}
		}
	}
	[Serializable]
	public class GetParticipantiResponse : Response
	{
		private List<String> participanti;

		public GetParticipantiResponse(List<String> friends)
		{
			this.participanti = friends;
		}

		public virtual List<String> Participanti
		{
			get
			{
				return participanti;
			}
		}
	}

	[Serializable]
	public class GetInscrieriResponse : Response
	{
		private List<String> inscrieri;

		public GetInscrieriResponse(List<String> friends)
		{
			this.inscrieri = friends;
		}

		public virtual List<String> Inscrieri
		{
			get
			{
				return inscrieri;
			}
		}
	}
	public interface UpdateResponse : Response
	{
	}

	[Serializable] 
	public class LoggedInResponse : UpdateResponse
	{
		private UserDTO userDto;

		public LoggedInResponse(UserDTO friend)
		{
			this.userDto = friend;
		}

		public virtual UserDTO UserDto
		{
			get
			{
				return userDto;
			}
		}
	}

	[Serializable]
	public class FriendLoggedOutResponse : UpdateResponse
	{
		private UserDTO friend;

		public FriendLoggedOutResponse(UserDTO friend)
		{
			this.friend = friend;
		}

		public virtual UserDTO Friend
		{
			get
			{
				return friend;
			}
		}
	}


	[Serializable]
	public class ParticipantAdaugatResponse : UpdateResponse
	{
		private InscriereDTO inscriereDto;

		public ParticipantAdaugatResponse(InscriereDTO inscriereDto)
		{
			this.inscriereDto = inscriereDto;
		}

		public virtual InscriereDTO InscriereDto
		{
			get
			{
				return inscriereDto;
			}
		}
	}

}