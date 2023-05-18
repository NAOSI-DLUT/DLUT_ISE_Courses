package dao;
import java.util.List;
import entity.employees;

public interface employeesDao {
    int addEmployees(employees emp);
    int delEmployees(int employees_id);
    int modEmployees(employees emp);
    List<employees> selEmployees();
    List<employees> selIDEmployees(Integer employee_id);
    List<employees> callProcedure();
}