
namespace Lab10.Repository.Validator
{
    interface IValidator<E>
    {
        void Validate(E e);
    }
}