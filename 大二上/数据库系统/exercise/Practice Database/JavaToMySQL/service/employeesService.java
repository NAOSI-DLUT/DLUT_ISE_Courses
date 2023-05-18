package service;
import java.util.List;
import entity.employees;

public interface employeesService {
    int addEmployees(employees emp);
    int delEmployees(int employee_id);
    int modEmployees(employees emp);
    List<employees> selEmployees();
    List<employees> selIDEmployees(Integer employee_id);
    List<employees> callProcedure();
}
