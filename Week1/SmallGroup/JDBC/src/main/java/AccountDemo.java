import com.cc.pojo.Account;
import org.junit.jupiter.api.Test;


import java.util.List;


/**
 * @author 32119
 */
public class AccountDemo {

    @Test
    public void testQuery() {
        try {
            String sql1 = "select id,username,password from account where id =?";
            Account acc1 = CRUDUtils.query(sql1, Account.class, 1);
            System.out.println(acc1);

            String sql2 = "select id,username,password from account where id =?";
            Account acc2 = CRUDUtils.query(sql2, Account.class, 2);
            System.out.println(acc2);

            String sql3 = "select id,username,password from account where id <=?";
            List<Account> accs = CRUDUtils.queryMore(sql3, Account.class, 2);
            System.out.println(accs);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Test
    public void testAdd() {
        try {
            Object[] params = {"wangwu", "7891"};
            String sql = "insert into account(username,password) values(?,?)";
            int update = CRUDUtils.update(sql, params);
            System.out.println(update);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

   @Test
    public void testDelete() {
        try {
            String sql = "delete from account where id = ?";
            int update = CRUDUtils.update(sql, 9);
            System.out.println(update);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Test
    public void testModify() {
        try {
            Object[] params = {"VIP", "88888888", "2"};
            String sql = "update account set username = ?,password = ? where id = ?";
            int update = CRUDUtils.update(sql, params);
            System.out.println(update);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Test
    public void testModify1() {
        try {
            Object[] params = {"666666", "2"};
            String sql = "update account set password = ? where id = ?";
            int update = CRUDUtils.update(sql, params);
            System.out.println(update);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}



