# Class

- Define class Student, School and Major. 

```
enum MajorType { CE, EE, ME, UD};
class Major {
private:
  MajorType majorType ;
public:
```

```
class Student {
private:
  string name ;
  float gpa ;
  Major major ;
public:
…
} ;
```

```
class School {
private:
  string schoolName ;
  vector<Student> students ;
public:
…
} ;
```
