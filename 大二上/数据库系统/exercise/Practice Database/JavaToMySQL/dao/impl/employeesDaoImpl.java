package dao.impl;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import dao.employeesDao;
import entity.employees;
import Utils.BaseDao;

public class employeesDaoImpl extends BaseDao implements employeesDao {
    //implement Database and object
    //connect object
    private Connection connect = null;
    //preparedStatement object
    private PreparedStatement pstatement = null;
    //callableStatement object
    private CallableStatement cstatement = null;
    //resultSet object
    private ResultSet result = null; 

    //add
    public int addEmployees(employees emp)
    {
        String sql = 
    "insert into employees (employee_id, first_name, last_name, job_id, department_id) values (?, ?, ?, ?, ?)";
        Object[] params = 
        {
            emp.getemployee_id(), emp.getfirst_name(), emp.getlast_name(), 
            emp.getjob_id(), emp.getdepartment_id()
        };
        return this.excuteDML(sql, params);
    }

    //delete
    public int delEmployees(int employee_id)
    {
        String sql = "delete from employees where employee_id = ?";
        Object[] params = { employee_id };
        return this.excuteDML(sql, params);
    }

    //nodify
    public int modEmployees(employees emp)
    {
        String sql = 
    "update employees set first_name = ?, last_name = ?, job_id = ?, department_id = ? where employee_id = ?";
        Object[] params = 
        {
            emp.getfirst_name(), emp.getlast_name(), emp.getjob_id(), emp.getdepartment_id(), 
            emp.getemployee_id()
        };
        return this.excuteDML(sql, params);
    }

    //query
    public List<employees> selEmployees()
    {
        List<employees> list = new ArrayList<employees>();
        
        try
        {
            //get database connect object
            connect = this.getConnection();
            String sql = "select * from employees";
            //create prepared statement
            pstatement =this.createPreparedStatement(connect, sql);
            //excute DQL sentence
            result = pstatement.executeQuery();
            while (result.next())
            {
                employees emp = new employees();
                emp.setemployee_id(result.getInt("employee_id"));
                emp.setfirst_name(result.getString("first_name"));
                emp.setlast_name(result.getString("last_name"));
                emp.setemail(result.getString("email"));
                emp.setphone_number(result.getString("phone_number"));
                emp.setjob_id(result.getString("job_id"));
                emp.setsalary(result.getDouble("salary"));
                emp.setcommission_pct(result.getDouble("commission_pct"));
                emp.setmanager_id(result.getInt("manager_id"));
                emp.setdepartment_id(result.getInt("department_id"));
                emp.sethiredate(result.getDate("hiredate"));
                list.add(emp);
            }
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
        finally
        {
            this.closeAll(connect, pstatement, result);
        }
        return list;
    }

    //query by ID
    public List<employees> selIDEmployees(Integer employee_id)
    {
        List<employees> list = new ArrayList<employees>();
        try
        {
            //get database connect object
            connect = this.getConnection();
            String sql = "select * from employees where employee_id = ?";
            pstatement =this.createPreparedStatement(connect, sql);
            pstatement.setInt(1, employee_id);
            result = pstatement.executeQuery();
            while (result.next())
            {
                employees emp = new employees();
                emp.setemployee_id(result.getInt("employee_id"));
                emp.setfirst_name(result.getString("first_name"));
                emp.setlast_name(result.getString("last_name"));
                emp.setemail(result.getString("email"));
                emp.setphone_number(result.getString("phone_number"));
                emp.setjob_id(result.getString("job_id"));
                emp.setsalary(result.getDouble("salary"));
                emp.setcommission_pct(result.getDouble("commission_pct"));
                emp.setmanager_id(result.getInt("manager_id"));
                emp.setdepartment_id(result.getInt("department_id"));
                emp.sethiredate(result.getDate("hiredate"));
                list.add(emp);
            }
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
        finally
        {
            this.closeAll(connect, pstatement, result);
        }
        return list;
    }

    //call procedure
    public List<employees> callProcedure()
    {
        List<employees> list = new ArrayList<employees>();
        try
        {
            //get connect object
            connect = this.getConnection();
            cstatement = connect.prepareCall("call ADMQ()");
            result = cstatement.executeQuery();
            while (result.next())
            {
                employees emp = new employees();
                emp.setemployee_id(result.getInt("employee_id"));
                emp.setfirst_name(result.getString("first_name"));
                emp.setlast_name(result.getString("last_name"));
                emp.setemail(result.getString("email"));
                emp.setphone_number(result.getString("phone_number"));
                emp.setjob_id(result.getString("job_id"));
                emp.setsalary(result.getDouble("salary"));
                emp.setcommission_pct(result.getDouble("commission_pct"));
                emp.setmanager_id(result.getInt("manager_id"));
                emp.setdepartment_id(result.getInt("department_id"));
                emp.sethiredate(result.getDate("hiredate"));
                list.add(emp);
            }
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
        finally
        {
            this.closeAll(connect, cstatement, result);
        }
        return list;
    }
}