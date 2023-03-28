import java.lang.reflect.Field;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.ArrayList;
import java.util.List;

/**
 * @author 32119
 */
public class CRUDUtils {

    /**
     * 此方法是通用的执行增删改的方法
     *
     * @param sql    SQL语句
     * @param params 占位符的值
     * @return update 更新数据的条数
     */
    public static int update(String sql, Object... params) {
        //获取连接
        Connection conn = null;
        PreparedStatement psmt = null;
        try {
            conn = JDBCUtils.getConnection();
            psmt = conn.prepareStatement(sql);
            if (params != null && params.length > 0) {
                for (int i = 0; i < params.length; i++) {
                    psmt.setObject(i + 1, params[i]);
                }
            }
            int row = psmt.executeUpdate();
            //返回更新数据的条数
            return row;
        } catch (Exception e) {
            //处理异常
            e.printStackTrace();
        } finally {
            //释放资源
            JDBCUtils.release(conn, psmt, null);
        }
        return 0;
    }


    /**
     * 通用的查询方法（返回单条记录）
     *
     * @param sql    SQL语句
     * @param clazz  查询的结果需要封装的实体类
     * @param params 占位符的值
     * @param <T>    具体操作的实体类
     * @return 返回特定的泛型
     */
    public static <T> T query(String sql, Class<T> clazz, Object... params) {
        //获取连接
        Connection conn = null;
        //对sql进行预编译
        PreparedStatement psmt = null;
        //执行查询
        ResultSet rs = null;
        try {
            conn = JDBCUtils.getConnection();
            psmt = conn.prepareStatement(sql);
            //设置占位符
            if (params != null && params.length > 0) {
                //数组的下标是从0开始，？的编号是1开始
                for (int i = 0; i < params.length; i++) {
                    psmt.setObject(i + 1, params[i]);
                }
            }
            rs = psmt.executeQuery();
            //获取查询的结果集的元数据信息
            ResultSetMetaData rsmd = rs.getMetaData();
            //通过ResultSetMetaData获取结果集的列数
            int count = rsmd.getColumnCount();
            //处理结果集
            while (rs.next()) {
                //要求这个Javabean类型必须有无参构造
                T t = clazz.newInstance();
                //循环每一行有几列
                for (int i = 0; i < count; i++) {
                    //第几列的名称
                    //如果sql中没有取别名，那么就是列名，如果有别名，返回的是别名
                    String fieldName = rsmd.getColumnLabel(i + 1);
                    //该列的值
                    Object value = rs.getObject(fieldName);
                    //设置obj对象的某个属性中
                    //获取成员变量
                    Field field = clazz.getDeclaredField(fieldName);
                    field.setAccessible(true);
                    field.set(t, value);
                }
                return t;
            }
        } catch (Exception e) {
            //处理异常
            e.printStackTrace();
        } finally {
            //释放资源
            JDBCUtils.release(conn, psmt, rs);
        }
        return null;
    }

    /**
     * 通用的查询方法（返回多条记录）
     *
     * @param clazz  查询的结果需要封装的实体类
     * @param sql    SQL语句
     * @param params 占位符的值
     * @param <T>    具体操作的实体类
     * @return 返回特定的泛型
     */
    public static <T> List<T> queryMore(String sql, Class<T> clazz, Object... params) {
        Connection conn = null;
        PreparedStatement psmt = null;
        ResultSet rs = null;
        try {
            conn = JDBCUtils.getConnection();
            psmt = conn.prepareStatement(sql);
            for (int i = 0; i < params.length; i++) {
                psmt.setObject(i + 1, params[i]);
            }
            rs = psmt.executeQuery();
            ResultSetMetaData rsmd = rs.getMetaData();
            //通过ResultSetMetaData获取结果集的列数
            int count = rsmd.getColumnCount();
            //创建集合对象
            ArrayList<T> list = new ArrayList<>();
            while (rs.next()) {
                T t = clazz.newInstance();
                for (int i = 0; i < count; i++) {
                    Object value = rs.getObject(i + 1);
                    String fieldName = rsmd.getColumnLabel(i + 1);
                    Field field = clazz.getDeclaredField(fieldName);
                    field.setAccessible(true);
                    field.set(t, value);
                }
                list.add(t);
            }
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.release(conn, psmt, rs);
        }
        return null;
    }
}
