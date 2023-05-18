package service.impl;

import java.util.ArrayList;
import java.util.List;
import dao.employeesDao;
import dao.impl.employeesDaoImpl;
import entity.employees;
import service.employeesService;

public class employeesServiceImpl implements employeesService {
    //create Dao object points to Dao implents
    //interface object points to implements class
    private employeesDao empDao = new employeesDaoImpl();

    //add
    public int addEmployees(employees emp)
    {
        int result = 0;
        if (emp != null)
        {
            if (emp.getemployee_id() != null)
            {
                result = empDao.addEmployees(emp);
            }
        }
        return result;
    }

    //delete
    public int delEmployees(int employee_id)
    {
        int result = 0;
        result = empDao.delEmployees(employee_id);
        return result;
    }

    //modify
    public int modEmployees(employees emp)
    {
        int result = 0;
        if (emp != null)
        {
            result = empDao.modEmployees(emp);
        }
        return result;
    }

    //query
    public List<employees> selEmployees()
    {
        return empDao.selEmployees();
    }

    //query by ID
    public List<employees> selIDEmployees(Integer employee_id)
    {
        List<employees> list = new ArrayList<employees>();
        list = empDao.selIDEmployees(employee_id);
        return list;
    }

    //call procedure
    public List<employees> callProcedure()
    {
        List<employees> list = new ArrayList<employees>();
        list = empDao.callProcedure();
        return list;
    }
}