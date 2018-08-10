class student
{
    size_t id;
    char* name;
public:
    student(size_t id, const char* name)
    {
        this->id = id;
        size_t len = strlen(name);
        this->name = new char[len+1];
        strcpy(this->name,name);
    }

    void show()
    {
        cout<<name<<'\n';
    }
};