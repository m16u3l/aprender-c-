#include <iostream>
#include <cstring>

using namespace std;

class relationship_a
{
	char* name;
public:
	relationship_a(const char* name){
		size_t len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
	}

	char* get_name(){
		return name;
	}
//	~relationship_a();	
};

class relationship_b
{
	char* name;
public:
	relationship_b(const char* name){
		size_t len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
	}
//	~relationship_b();
	
};

class tool_a
{
	char* name;
public:
	tool_a(const char* name){
		size_t len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
	}

	char* get_name(){
		return name;
	}

//	~tool_a();
	
};

class tool_b
{
	char* name;
public:
	tool_b(const char* name){
		size_t len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
	}
//	~tool_b();
	
};

class tool_c
{
	char* name;
public:
	tool_c(const char* name){
		size_t len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
	}
//	~tool_c();
	
};

class canvas
{
	size_t size;
	char* name;
public:
	canvas(const char* name, size_t size){
		size_t len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
		this->size = size;
		cout<<"Se creo un canvas: "<<name<<" De tamano: "<<size<<endl;
	}
//	~canvas();
};

class tool_box
{
	char* name;

public:
	tool_box(const char* name){
		size_t len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name,name);
		cout<<"Se creo un tool box: "<<name<<endl;
	}
//	~tool_box();

	void add_tool(tool_a tool) {
		cout<<"Se anade al tool box: "<<tool.get_name()<<endl;
	}

	void add_tool_relationship(relationship_a relationship){
		cout<<"Se anade al tool box: "<<relationship.get_name()<<endl;
	}
};

class relationship
{
public:
	relationship();
//	~relationship();
	
};


class tool
{
	char* name;
public:
	tool(const char* name){
		size_t len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name, name);
	}
//	~tool();
	
};

class class_object{
	
};

int main(int argc, char const *argv[])
{
	canvas canvas_uml{"uml canvas", 200};	
	tool_box uml_tool_box{"uml box"};

	tool_a class_tool{"class"};
	tool_b interface_tool{"interface"};
	tool_c abstract_class_tool{"abstract class"};

	relationship_a aggregation_realtionship{"aggregation"};
	relationship_b composition_relationship{"composition"};

	uml_tool_box.add_tool(class_tool);
/*	uml_tool_box.add_tool(interface_tool);
	uml_tool_box.add_tool(abstract_class_tool);
*/
	uml_tool_box.add_tool_relationship(aggregation_realtionship);
/*	uml_tool_box.add_tool_relationship(composition_relationship);
*/
//	class_object class_1{class_tool.add_to_canvas(uml_canvas, "class 1")};
/*	class_object class_2{class_tool.add_to_canvas(uml_canvas, "class 2")};
	class_object class_3{class_tool.add_to_canvas(uml_canvas, "class_3")};

	abstract_class_object abstract_class1{abstract_class_tool.add_to_canvas(uml_canvas, "abstract class 1")};

	relationship_object relationship_object_1{relationship_a.add_relationship(uml_canvas, class_1, class_2)};
	relationship_object relationship_object_2{relationship_b.add_relationship(uml_canvas, class_3, class_2)};

	class_1.edit_name("class_name");
	class_3.remove();
	class_2.move();
	relationship_object_1.remove();
*/
	return 0;
}