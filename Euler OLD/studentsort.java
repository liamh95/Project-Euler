class Student {
        //data fields
        private String name;
        private int id;
        private java.util.Date dateCreated;
       
        //no arg constructor
        public Student(){
                        this.name = "JohnDoe";
                        this.id = 000000;
        }
       
        //arg constructor
        public Student (String name, int id){
                this.name = name;
                this.id = id;
                dateCreated = new java.util.Date();
        }

       
        //since private data-getters
        public String getName(){
                return name;
        }
       
        public int getID(){
                return id;
        }
       
        //setters
        public void setID(int id){
                this.id = id;
        }
       
        public void setName(String name){
                this.name = name;
        }
       
        public java.util.Date getDateCreated(){
                return dateCreated;
        }

        public Student(Student another){
        	name = another.getName();
        	id = another.getID();
        	dateCreated = another.getDateCreated();
        }
}

class Course{
        //data fields
        //store name, array of Student objs, num of current students
        private String courseName;
        private Student [] list = new Student [10];
        private static int numEnrolled=0;
       
        //default no arg constructor
        public Course (){
                this.courseName = "CS000 Section 0";
                for (int i=0;i<10;i++){
                        this.list[i] = new Student();
                }
        }
       
        //arg constructor; takes course name
        //capacity of class is 10
        public Course (String courseName){
                this.courseName = courseName;
                for (int i=0;i<10;i++){
                        this.list[i] = new Student (); //#help
                }
        }
       
        //getters for vars     
        public String getCourseName(){
                return courseName;
        }
       
        public Student [] getList(){
                return list;
        }
       
        public int getNumEnrolled(){
                return numEnrolled;
        }
       
       
        //ID sorting method
        //#HELP #MAYDAY #APPEALFORURGENTASSISTANCE
        public void idSort(){
                Student temp = new Student("asdf",00001);
                for (int i=0; i<numEnrolled-1; i++){
                        double currentMin = this.list[i].getID();
                        int currentMinIndex = i;
                        for (int j = i+1; j<numEnrolled; j++){
                                if (currentMin > this.list[j].getID()){
                                        currentMin = this.list[j].getID();
                                        currentMinIndex = j;
                                }
                        }
                        if (currentMinIndex != i){
                                temp = list[currentMinIndex];
                                list[currentMinIndex] = list[i];
                                list[i] = temp;
                        }
                }
        }
       
        //method to add students
        //if class is full, method prints: Sorry, the class is closed
        public void addStudent(String name, int id){
                if (numEnrolled<10){
                        this.list[numEnrolled] = new Student (name,id);
                        System.out.println("Student named "+name+" with ID "+id+"has been added to "+this.courseName);
                        numEnrolled += 1;
                }
                else {
                        System.out.println("\nSorry, this class is closed");
                }
        }
       
        //method to drop students
        public void dropStudent (String name, int id){
                int drop = 9;
                for (int i=0;i<10;i++){
                        if (id == this.list[i].getID()){
                                this.list[i] = new Student();
                                drop = i;
                                System.out.println("Student with ID "+id+" and name "+name+", will be dropped from "+this.courseName);
                                numEnrolled -= 1;
                        }
                }
                for (int i=drop;i<9;i++){
                        this.list[i] = this.list[i+1];
                }
                this.list[9]= new Student();
        }
       
        //method to display course roster
        public void printRoster(){
                System.out.println();
                System.out.println("Course: "+this.courseName);
                System.out.println("*************************");
                System.out.println("Total number of student currently enrolled: "+numEnrolled);
                idSort();
                for (int i=0; i<numEnrolled; i++){
                        System.out.println((i+1)+". "+this.list[i].getName()+" - "+this.list[i].getID());
                }
                System.out.println();
        }
       
}

	

     
public class studentsort {
     
            public static void main(String[] args) {
                    Course cs101 = new Course ("CS101 Section 5");
                    cs101.addStudent("Smith, John", 12345);
                    cs101.addStudent("Jones, Mary", 23456);
                    cs101.addStudent("May, Cristiana", 82396);
                    cs101.printRoster();
                    cs101.addStudent("Lord, Ken", 99999);
                    cs101.addStudent("Waxman, Jerry", 12396);
                    cs101.addStudent("Troudt, Edgar", 52956);
                    cs101.addStudent("Kendall, Richard", 42396);
                    cs101.addStudent("Schneider, Raymond", 32396);
                    cs101.addStudent("Jones, Kecia", 72396);
                    cs101.addStudent("Noni, Craig", 44396);
                    cs101.addStudent("testcase", 11111);
                    cs101.printRoster();
                    cs101.dropStudent("Jones, Mary", 23456);
                    cs101.printRoster();
            }
     
    }

