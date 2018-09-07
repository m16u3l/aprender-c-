#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

// This is a database in memory that can store objects.
// You can have several 'tables' (lists of objects) accessible by their name.
// Any "table" can have unlimited number of objects.
// You will be able to create tables, add objects to the tables, count number of tables and objects, filter, sort and find objects given an size_t ID.
// The memory_db will be in charge of releasing the objects stored into it.
//
// Restrictions:
// * Do not use anything we did not see in class. You can use std::string.
// * Memory leaks will cost you 10 points.
// * Program crashing will cost you 50 points.
// * Program not compiling will cost you 100% of your exam.

class lib_object{
     
     
public:
     lib_object()
     {}
     virtual ~lib_object()
     {}

     virtual string get_class_name()const
     {
          return "lib_object";
     }

     
};

class student: public lib_object
{
     size_t id_student;
     string first_name;
     string last_name;
public:
     student(size_t id, string first, string last)
     :id_student{id}, first_name{first}, last_name{last}
     {
     }
     ~student()
     {

     }
     size_t get_id()
     {
          return id_student;
     }
};

class course: public lib_object
{
     size_t id_course;
     string name_course;
public:
     course(size_t id, string name)
     :id_course{id}, name_course{name}
     {

     }
     ~course()
     {

     }

     size_t get_id()
     {
          return id_course;
     }
     
};

class table
{
     size_t len;
     size_t sizememory;
     lib_object** objs;
     string table_name;
public:
     table(string name)
     :len{0},sizememory{4}, objs{new lib_object*[4]}, table_name{name}
     {

     }

     ~table()
     {
          for(size_t i = 0; i < len; i++){
               delete objs[i];
          }
          delete[] objs;
     }

     const string get_name()
     {
          return table_name;
     }     

     const size_t get_len()
     {
          return len;
     }

     void add(lib_object* obj)
     {
          if(len<sizememory)
          {
               objs[len] = obj;
               len++;
          }else{
               size_t aux;
               aux = sizememory + 1;
               lib_object** array_aux = new lib_object*[aux];
               for(size_t i = 0; i < len; i++)
               {
                    array_aux[i] = objs[i];
               }         
               delete []objs;
               objs = array_aux;
               objs[len++] = obj;
               sizememory = aux;
          }         
     }


};

class memory_db
{
     size_t len;
     size_t sizememory;
     table** tables;
     size_t count;
public:
     memory_db()
     :len{0},sizememory{4}, tables{new table*[4]}, count{0}
     {}
     ~memory_db()
     {
          for(size_t i = 0; i < len; i++){
               delete tables[i];
          }
          delete[] tables;
     }

     size_t get_table_count()
     {
          return count;
     }

     void create_table(string str)
     {
          if(len<sizememory)
          {
               tables[len] = new table{str};
               len++;
          }else{
               size_t aux;
               aux = sizememory + 1;
               table** array_aux = new table*[aux];
               for(size_t i = 0; i < len; i++)
               {
                    array_aux[i] = tables[i];
               }         
               delete []tables;
               tables = array_aux;
               tables[len++] = new table{str};
               sizememory = aux;
          }  
          count++;
     }

     bool add_object(const string name, student* student)
     {
          for (size_t i = 0; i < count; ++i)
          {
               if (name.compare(tables[i]->get_name()) == 0)
               {

                    tables[i]->add(student);
                    return true;
               }
          }
          return false;
     }

     bool add_object(const string name, course* course)
     {
          bool res = false;
          for (size_t i = 0; i < count; ++i)
          {
               if (name.compare(tables[i]->get_name()) == 0)
               {
                    tables[i]->add(course);
                    return true;
               }
          }
          return res;
     }

     int get_object_count(const string name)
     {
          for (size_t i = 0; i < count; ++i)
          {
               if (name.compare(tables[i]->get_name()) == 0)
               {
                    return tables[i]->get_len();
               }
          }
          return -1;
     }
};

bool test0()
{
     memory_db db;
     db.create_table("students");
     db.create_table("courses");

     return db.get_table_count() == 2;
}

bool test1()
{
     memory_db db;

     db.create_table("students");
     db.create_table("courses");

     bool r = db.add_object("students", new student(123, "juan", "perez"));
     r = db.add_object("students", new student(125, "gael", "garcia"));

     return r && db.get_object_count("students") == 2 && db.get_object_count("courses") == 0;
}    

bool test2()
{
     memory_db db;

     db.create_table("students");
     bool r = db.add_object("courses", new course(1, "devint26"));

     return r == false; // false because 'courses' table does not exist in this db object
}
/*
bool test3()
{
     memory_db db;

     db.create_table("students");
     db.add_object("students", new student(123, "juan", "perez"));
     db.add_object("students", new student(125, "gael", "garcia"));

     auto st = (student*) db.find("students", 125);

     return st != nullptr && st->get_last_name() == "garcia";
}

bool test4()
{
     memory_db db;

     db.create_table("students");
     db.create_table("courses");
     db.add_object("students", new student(123, "juan", "perez"));
     db.add_object("students", new student(125, "gael", "garcia"));
     db.add_object("courses", new course(1, "math"));
     db.add_object("students", new student(128, "luis", "miguel"));
     db.add_object("courses", new course(2, "physics"));
     db.add_object("students", new student(130, "marco", "peredo"));
     db.add_object("courses", new course(3, "chemistry"));

     auto list = db.get_all("friends");

     return list.get_count() == 0; // because "friends" table does not exist in this memory_db
}

bool test5()
{
     memory_db db;

     db.create_table("students");
     db.create_table("courses");
     db.add_object("students", new student(123, "juan", "perez"));
     db.add_object("students", new student(125, "gael", "garcia"));
     db.add_object("courses", new course(1, "math"));
     db.add_object("students", new student(128, "luis", "miguel"));
     db.add_object("courses", new course(2, "physics"));
     db.add_object("students", new student(130, "marco", "peredo"));
     db.add_object("courses", new course(3, "chemistry"));

     auto list = db.get_all("courses");

     return list.get_count() == 3 && list.get(0).get_id() == 1 && list.get(1).get_id() == 2 && list.get(2).get_id() == 3;
}

bool test6()
{
     memory_db db;

     db.create_table("students");
     db.add_object("students", new student(123, "juan", "perez"));
     db.add_object("students", new student(125, "gael", "garcia"));
     db.add_object("students", new student(128, "luis", "miguel"));
     db.add_object("students", new student(130, "marco", "peredo"));

     auto list = db.select_from("students", student_starts_with_pe);

     return list.get_count() == 2 &&
                ((student&)list.get(0)).get_last_name() == "perez" &&
                ((student&)list.get(1)).get_last_name() == "peredo";
}

bool test7()
{
     return test6();
}


bool test8()
{
     memory_db db;

     db.create_table("students");
     db.add_object("students", new student(1, "jean michel", "jarre"));
     db.add_object("students", new student(1, "armin", "van buuren"));
     db.add_object("students", new student(1, "vince", "clarke"));
     db.add_object("students", new student(1, "chris", "lowe"));

     auto list = db.order_by("students", compare_by_first_name);

     return list.get_count() == 4 &&
              ((student&)list.get(0)).get_first_name() == "armin" &&
              ((student&)list.get(1)).get_first_name() == "chris" &&
              ((student&)list.get(2)).get_first_name() == "jean michel" &&
              ((student&)list.get(3)).get_first_name() == "vince";
}

bool test9()
{
     return test8();
}

*/
int main()
{
     bool r[10];

     r[0] = test0();
     r[1] = test1();
     r[2] = test2();/*
     r[3] = test3();
     r[4] = test4();
     r[5] = test5();
     r[6] = test6();
     r[7] = test7();
     r[8] = test8();
     r[9] = test9();
*/
     auto score = 0;

     for (int i = 0; i < 3; i++)
     {
           int sc = r[i] * 10;
           cout << "TEST " << i << ": Result: " << sc << "\n";
           score += sc;
     }

     puts("**************");
     cout << "TOTAL SCORE: " << score << "\n";

     getchar();
     return 0;
}