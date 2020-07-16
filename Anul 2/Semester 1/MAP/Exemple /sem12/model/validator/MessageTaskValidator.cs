using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Curs12.Repository;
namespace Curs12.Repository.Validator
{
    class MessageTaskValidator : IValidator<MessageTask>
    {
        public void Validate(MessageTask e)
        {
            bool valid = true;
            if (valid == false)
            {
                throw new ValidationException("Obiectul nu e valid");
            }
        }
    }
}
