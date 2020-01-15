using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab10.Repository.Validator
{
    class ElevValidator : IValidator<Elev>
    {
        public void Validate(Elev e)
        {
            if (e.Nume.Equals("") || e.Scoala.Equals(""))
            {
                throw new ValidationException("Elevul nu e valid");
            }
        }
    }
}