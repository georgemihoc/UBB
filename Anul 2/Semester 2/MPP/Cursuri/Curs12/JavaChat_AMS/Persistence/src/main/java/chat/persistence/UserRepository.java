package chat.persistence;

import chat.model.User;

/**
 * Created by grigo on 3/17/17.
 */
public interface UserRepository extends ICrudRepository<String,User> {
    User findBy(String username);
    User findBy(String username, String pass);
    Iterable<User> getFriendsOf(User user);
}
