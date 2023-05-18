package Utils;
import java.sql.*;

public class BaseDao
{
    //4 static values: driver, url, user, password
    //a database called myemployees
    //has 5 tables: departments, employees, job_grades, jobs, locations
    public static final String driver = "com.mysql.jdbc.cj.Driver";
    public static final String url = "jdbc:mysql://127.0.0.1/myemployees";
    public static final String user = "root";
    public static final String password = "123456frank";
    
    //load driver
    static 
    {
        try
        {
            Class.forName(driver);
        }
        catch (ClassNotFoundException e)
        {
            e.printStackTrace();
        }
    }

    //get connection by DriverManager
    public static Connection getConnection() throws SQLException
    {
        return DriverManager.getConnection(url, user, password);
    }

    //get PreparedStatemnt by connection
    public PreparedStatement createPreparedStatement(Connection connect, String sql, Object... params) 
                                                    throws SQLException
    {
        PreparedStatement pstatement = connect.prepareStatement(sql);
        if (params != null && params.length > 0)
        {
            int i = 1;
            for (Object p : params)
            {
                pstatement.setObject(i, p);
                i++;
            }
        }
        return pstatement;
    }

    //DML
    public int excuteDML(String sql, Object... params)
    {
        Connection connect = null;
        PreparedStatement pstatement = null;
        int result = 0;
        try
        {
            connect = this.getConnection();
            pstatement = this.createPreparedStatement(connect, sql, params);
            result = pstatement.executeUpdate();
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
        finally
        {
            this.closeAll(connect, pstatement, null);
        }
        return result;
    }

    //closeAll
    public void closeAll(Connection connect, PreparedStatement pstatement, ResultSet result)
    {
        try
        {
            if (connect != null)
            {
                connect.close();
            }
            if (pstatement != null)
            {
                pstatement.close();
            }
            if (result != null)
            {
                result.close();
            }
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
    }
}