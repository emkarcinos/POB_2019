public class Employee_main{
    public static void main(String []args){
        Employee emp1=new Employee("Marcin");
        emp1.salary=1500;
        Employee emp2=new Employee("Tomasz");
        emp2.salary=1900;
        emp1.compare(emp2);

    }
}