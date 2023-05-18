package entity;
import java.util.Date;

public class employees {
    private Integer employee_id;
    private String first_name;
    private String last_name;
    private String email;
    private String phone_number;
    private String job_id;
    private Double salary;
    private Double commission_pct;
    private Integer manager_id;
    private Integer department_id;
    private Date hiredate;

    //default constructor
    public employees()
    {}

    //override constructor
    public employees(Integer employee_id, String first_name, String last_name, String email,
                     String phone_number, String job_id, Double salary, Double commission_pct,
                     Integer manager_id, Integer department_id, Date hiredate)
    {
        super();
        this.employee_id = employee_id;
        this.first_name = first_name;
        this.last_name = last_name;
        this.email = email;
        this.phone_number = phone_number;
        this.job_id = job_id;
        this.salary = salary;
        this.commission_pct = commission_pct;
        this.manager_id = manager_id;
        this.department_id = department_id;
        this.hiredate = hiredate;
    }

    //override constructor
    public employees(Integer employee_id, String first_name, String last_name, String job_id, 
                     Integer department_id)
    {
        super();
        this.employee_id = employee_id;
        this.first_name = first_name;
        this.last_name = last_name;
        this.job_id = job_id;
        this.department_id = department_id;
    }
    
    //get function and set function
    public Integer getemployee_id()
    {
        return employee_id;
    }
    public void setemployee_id(Integer employee_id)
    {
        this.employee_id = employee_id;
    }

    public String getfirst_name()
    {
        return first_name;
    }
    public void setfirst_name(String first_name)
    {
        this.first_name = first_name;
    }

    public String getlast_name()
    {
        return last_name;
    }
    public void setlast_name(String last_name)
    {
        this.last_name = last_name;
    }

    public String getemail()
    {
        return email;
    }
    public void setemail(String email)
    {
        this.email = email;
    }

    public String getphone_number()
    {
        return phone_number;
    }
    public void setphone_number(String phone_number)
    {
        this.phone_number = phone_number;
    }

    public String getjob_id()
    {
        return job_id;
    }
    public void setjob_id(String job_id)
    {
        this.job_id = job_id;
    }

    public Double getsalary()
    {
        return salary;
    }
    public void setsalary(Double salary)
    {
        this.salary = salary;
    }

    public Double getcommission_pct()
    {
        return commission_pct;
    }
    public void setcommission_pct(Double commission_pct)
    {
        this.commission_pct = commission_pct;
    }

    public Integer getmanager_id()
    {
        return manager_id;
    }
    public void setmanager_id(Integer manager_id)
    {
        this.manager_id = manager_id;
    }

    public Integer getdepartment_id()
    {
        return department_id;
    }
    public void setdepartment_id(Integer department_id)
    {
        this.department_id = department_id;
    }

    public Date gethiredate()
    {
        return hiredate;
    }
    public void sethiredate(Date hiredate)
    {
        this.hiredate = hiredate;
    }
}
