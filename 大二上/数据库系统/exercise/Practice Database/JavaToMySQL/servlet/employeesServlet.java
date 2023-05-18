package servlet;
import java.util.List;
import java.util.Scanner;
import entity.employees;
import service.employeesService;
import service.impl.employeesServiceImpl;
//import java.util.Date;

public class employeesServlet {
    private static employeesService empService = new employeesServiceImpl();

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        do
        {
            System.out.println("DataBase myployees");
            System.out.println("1. Add");
            System.out.println("2. Delete");
            System.out.println("3. Modify");
            System.out.println("4. Query");
            System.out.println("5. Query by 'employee_id'");
            System.out.println("6. Call procedure ADMQ");
            int choice = input.nextInt();
            switch (choice)
            {
                case 1://add
                    addEmployees(input);
                    break;
                case 2://delete
                    delEmployees(input);
                    break;
                case 3://modify
                    modEmployees(input);
                    break;
                case 4://query
                    selEmployees();
                    break;
                case 5://query by id
                    selIDEmployees(input);
                    break;
                case 6://call procedure
                    callProcedure();
                    break; 
                default:
                    System.out.println("Error. ");
                    break;
            }
        } while (true);
    }

    /*
    in order to test the project quickly, just add or modify 5 fields:
    employee_id(primary key), first_name, last_name, job_id(foreign key), department_id(foreign key)
    add or modify the values, also need to change the SQL sentence in 'employeesDaoImpl.java'
    5 functions defination:
    */
    //add
    private static void addEmployees(Scanner input)
    {
        System.out.println("Input: ");
        System.out.println("employee_id: ");
        Integer employee_id = input.nextInt();
        System.out.println("first_name: ");
        String first_name = input.next();
        System.out.println("last_name: ");
        String last_name = input.next();
        /*
        System.out.println("email: ");
        String email = input.next();
        System.out.println("phone_number: ");
        String phone_number = input.next();
        */
        System.out.println("job_id: ");
        String job_id = input.next();
        /*
        System.out.println("salary: ");
        Double salary = input.nextDouble();
        System.out.println("commission_pct: ");
        Double commission_pct = input.nextDouble();
        System.out.println("manager_id: ");
        Integer manager_id = input.nextInt();
        */
        System.out.println("department_id: ");
        Integer department_id = input.nextInt();
        /*
        Date hiredate = new Date(System.currentTimeMillis());
        */

        /*
        employees emp = new employees(employee_id, first_name, last_name, email, phone_number, job_id,
                                      salary, commission_pct, manager_id, department_id, hiredate);
        */
        employees emp = new employees(employee_id, first_name, last_name, job_id, department_id);
        int result = empService.addEmployees(emp);
        if (result > 0)
        {
            System.out.println("Add succeeded. ");
        }
        else
        {
            System.out.println("Add failed. ");
        }
    }

    //delete
    private static void delEmployees(Scanner input)
    {
        System.out.println("Input the employee_id: ");
        int employee_id = input.nextInt();
        
        int result = empService.delEmployees(employee_id);
        if (result > 0)
        {
            System.out.println("Delete succeeded.");
        }
        else
        {
            System.out.println("Delete failed. ");
        }
    }

    //modify
    private static void modEmployees(Scanner input)
    {
        System.out.println("Input: ");
        System.out.println("employee_id: ");
        Integer employee_id = input.nextInt();
        System.out.println("first_name: ");
        String first_name = input.next();
        System.out.println("last_name: ");
        String last_name = input.next();
        /*
        System.out.println("email: ");
        String email = input.next();
        System.out.println("phone_number: ");
        String phone_number = input.next();
        */
        System.out.println("job_id: ");
        String job_id = input.next();
        /*
        System.out.println("salary: ");
        Double salary = input.nextDouble();
        System.out.println("commission_pct: ");
        Double commission_pct = input.nextDouble();
        System.out.println("manager_id: ");
        Integer manager_id = input.nextInt();
        */
        System.out.println("department_id: ");
        Integer department_id = input.nextInt();
        
        employees emp = new employees();
        emp.setemployee_id(employee_id);
        emp.setfirst_name(first_name);
        emp.setlast_name(last_name);
        /*
        emp.setemail(email);
        emp.setphone_number(phone_number);
        */
        emp.setjob_id(job_id);
        /*
        emp.setsalary(salary);
        emp.setcommission_pct(commission_pct);
        emp.setmanager_id(manager_id);
        */
        emp.setdepartment_id(department_id);

        int result = empService.modEmployees(emp);
        if (result > 0)
        {
            System.out.println("Nodify succeeded. ");
        }
        else
        {
            System.out.println("Modify failed. ");
        }
    }

    //query
    private static void selEmployees()
    {
        List<employees> employeesAll = empService.selEmployees();
        for (employees e : employeesAll)
        {
            System.out.println("employee_id: " + e.getemployee_id() + 
                                "\tfirst_name: " + e.getfirst_name() + 
                                "\tlast_name: " + e.getlast_name() + 
                                "\temail: " + e.getemail() + 
                                "\tphone_number: " + e.getphone_number() + 
                                "\tjob_id: " + e.getjob_id() + 
                                "\tsalary: " + e.getsalary() + 
                                "\tcommission_pct: " + e.getcommission_pct() + 
                                "\tmanager_id: " + e.getmanager_id() + 
                                "\tdepartment_id: " + e.getdepartment_id());
        }
    }
    
    //query by ID
    private static  void selIDEmployees(Scanner input)
    {
        System.out.println("Input employee_id: ");
        Integer employee_id = input.nextInt();
        List<employees> employeesAll = empService.selIDEmployees(employee_id);

        for (employees e : employeesAll)
        {
            System.out.println("employee_id: " + e.getemployee_id() + 
                                "\tfirst_name: " + e.getfirst_name() + 
                                "\tlast_name: " + e.getlast_name() + 
                                "\temail: " + e.getemail() + 
                                "\tphone_number: " + e.getphone_number() + 
                                "\tjob_id: " + e.getjob_id() + 
                                "\tsalary: " + e.getsalary() + 
                                "\tcommission_pct: " + e.getcommission_pct() + 
                                "\tmanager_id: " + e.getmanager_id() + 
                                "\tdepartment_id: " + e.getdepartment_id());
        }
    }

    //call procedure
    private static void callProcedure()
    {
        System.out.println("Calling procedure ADMQ: ");
        List<employees> employeesAll = empService.callProcedure();
        for (employees e : employeesAll)
        {
            System.out.println("employee_id: " + e.getemployee_id() + 
                                "\tfirst_name: " + e.getfirst_name() + 
                                "\tlast_name: " + e.getlast_name() + 
                                "\temail: " + e.getemail() + 
                                "\tphone_number: " + e.getphone_number() + 
                                "\tjob_id: " + e.getjob_id() + 
                                "\tsalary: " + e.getsalary() + 
                                "\tcommission_pct: " + e.getcommission_pct() + 
                                "\tmanager_id: " + e.getmanager_id() + 
                                "\tdepartment_id: " + e.getdepartment_id());
        }
    }
}
