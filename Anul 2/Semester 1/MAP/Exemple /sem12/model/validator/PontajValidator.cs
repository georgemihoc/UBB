using Curs12.Repository.Validator;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Curs12.Repository.Validator
{
    class PontajValidator : IValidator<Pontaj>
    {
        public void Validate(Pontaj e)
        {
            bool valid = true;
            if (valid == false)
            {
                throw new ValidationException("Obiectul nu e valid");
            }
        }
    }
}
