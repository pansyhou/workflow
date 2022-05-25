import java.io.*;

public class Employee{
    String name;
    int age;
    String designation;
    double salary;
    public Employee (String name )
    {
        this.name=name;
    }

    public void emAge(int empAge)
    {
        age=empAge;
    }
    public void empDesignation(String empDesig)
    {
        designation=empDesig;
    }
    public void printEmployee()
    {
        System.out.println("名字："+name);
        System.out.println("年龄："+age);
        System.out.println("薪水：",+salary);
    }

    public static void main(String[] args)
    {
        Employee empone=new Employee("1123");
        empone.age(26);
        empone.designation("高级程序员");
        empone.salary(1000);
        empone.printEmployee();
    }
}

