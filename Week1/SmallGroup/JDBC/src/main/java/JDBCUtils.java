import java.io.FileInputStream;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

/**
 * @author 32119
 */
public class JDBCUtils {
    private static String driver = null;
    private static String url = null;
    private static String username = null;
    private static String password = null;


    static {
        try {
            InputStream in = new FileInputStream("D:\\code\\JDBC\\src\\main\\resources\\db.properties");
            Properties propertise = new Properties();
            propertise.load(in);

            driver = propertise.getProperty("driver");
            url = propertise.getProperty("url");
            username = propertise.getProperty("username");
            password = propertise.getProperty("password");

            Class.forName(driver);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 获取可用的连接对象
     *
     * @return connection
     */
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, username, password);
    }

    /**
     * 释放连接资源
     *
     * @param conn 连接对象
     * @param st   命令对象
     * @param rs   结果集对象
     */
    public static void release(Connection conn, Statement st, ResultSet rs) {
        if (rs != null) {
            try {
                rs.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if (st != null) {
            try {
                st.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
