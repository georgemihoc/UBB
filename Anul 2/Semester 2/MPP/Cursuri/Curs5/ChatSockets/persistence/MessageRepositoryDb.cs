using System.Collections.Generic;
using chat.model;
using System;
namespace chat.persistence
{
    public class MessageRepositoryDb:IMessageRepository
    {
        public void save(Message message)
        {
            Console.WriteLine("MessageDB [save]");
            var con=DBUtils.getConnection();

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "insert into messages (sender,receiver,mtext, mdata) values (@sender,@receiver,@mtext,@mdata)";
                var paramSender = comm.CreateParameter();
                paramSender.ParameterName = "@sender";
                paramSender.Value =message.Sender.Id ;
                comm.Parameters.Add(paramSender);
                var paramReceiver = comm.CreateParameter();
                paramReceiver.ParameterName = "@receiver";
                paramReceiver.Value =message.Receiver.Id ;
                comm.Parameters.Add(paramReceiver);
                var paramText = comm.CreateParameter();
                paramText.ParameterName = "@mtext";
                paramText.Value =message.Text ;
                comm.Parameters.Add(paramText);
                var paramData = comm.CreateParameter();
                paramData.ParameterName = "@mdata";
                paramData.Value =DateTime.Today ;
                comm.Parameters.Add(paramData);
                int rez=comm.ExecuteNonQuery();
                Console.WriteLine("MessageDB [save] rez={0}",rez);

            }
        }

        public void delete(int id)
        {
            throw new System.NotImplementedException();
        }

        public Message findOne(int id)
        {
            throw new System.NotImplementedException();
        }

        public void update(int id, Message e)
        {
            throw new System.NotImplementedException();
        }

        public IEnumerable<Message> getAll()
        {
            throw new System.NotImplementedException();
        }
    }
}