#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//
class birthday{                //class ngày tháng năm sinh để sau này lấy cho dễ
    int day;
    int month;
    int year;
    public:
      int getDay(){
          return day;
      }
      void setDay(int day){
          this->day = day;
      }
      int getMonth(){
          return month;
      }
      void setMonth(int month){
          this->month = month;
      }
      int getYear(){
          return year;
      }
      void setYear(int year){
          this->year = year;
      }
};

//nhan vien
class member {
private:
    string mID;       //mã nhân viên
    string mlname;    //họ và đệm
    string firstname; //tên
    string gID;       //mã đơn vị
    string pnumber;
    birthday ns;      //da_tri
    int gender;
    string position;
    float C_salary;   //hệ số lương
    int year_in;
    string degree;    //trình độ, cấp bậc
    string L_certificate; // bằng ngoại ngữ
public:
    member();
    member(string , string , string , string , string , birthday , int , string , float , int , string , string );
    void readfile_M(ifstream &);
    int getSalary(); //tinh luong    
    friend istream &operator >>(istream &in, member &);
    friend ostream &operator <<(ostream &out, member &);
    friend bool operator <(const member &, const member &);
    friend bool operator >(const member &, const member &);
};

member::member(){
    mID = "";
    mlname = "";
    firstname = "";
    gID = "";
    pnumber = "";
    ns.setDay(0);
    ns.setMonth(0);
    ns.setYear(0);
    gender = 0;
    position = "";
    C_salary = 0;
    year_in = 0;
    degree = "";
    L_certificate = "";
}

member::member(string mID, string mlname, string firstname, string gID, string pnumber, birthday ns, int gender, string pos, float C_salary, int year_in, string degree, string L_cer)
    :mID(mID),mlname(mlname),firstname(firstname),gID(gID),pnumber(pnumber),ns(ns),gender(gender),position(pos),
    C_salary(C_salary),year_in(year_in),degree(degree),L_certificate(L_cer){}

void member::readfile_M(ifstream &in) {
    string s;  //bỏ qua dòng đầu
    char t;    // đọc kí tự bỏ qua
    getline(in,mID,'|');
    getline(in, mlname, '|' );
    getline(in, firstname, '|');
    getline(in, gID, '|');
    getline(in,pnumber,'|');
    int day;
    in >> day;
    ns.setDay(day);
    in >>t;  // đọc |, bỏ qua nó
    int month;
    in >> month;
    ns.setMonth(month);
    in >>t;
    int year;
    in >> year;
    ns.setYear(year);
    in >>t;
    in >> gender;
    getline(in,s,'|');
    getline(in,position,'|');
    in >> C_salary;
    getline(in,s,'|');
    in >> year_in;
    getline(in,s,'|');
    getline(in,degree,'|');
    getline(in, L_certificate,'\n');
}

ostream &operator <<(ostream &out, member &m){
    //du nguyen    
    out<<setw(10)<<m.mID<<setw(25)<<m.mlname+m.firstname<<setw(10)<<m.gID<<setw(15)<<m.pnumber<<right<<setfill('0')<<setw(2)<<m.ns.getDay()
        <<"/"<<setw(2)<<m.ns.getMonth()<<"/"<<setfill(' ')<<left<<setw(10)<<m.ns.getYear()<<setw(10)<<m.gender<<setw(10)<<m.position
        <<setw(10)<<m.C_salary<<setw(10)<<m.year_in<<setw(10)<<m.degree<<setw(10)<<m.L_certificate<<endl;
    return out;
}

istream &operator >>(istream &in, member &m){
    int temp;
    int gt=0;
    string s;
    cout<<"Nhap ma nhan vien: ";
    in >> m.mID;
    cout<<"Nhap ho va ten dem: ";
    getline(in>>ws,m.mlname);
    m.mlname+=" ";
    cout<<"Nhap ten: ";
    getline(in>>ws,m.firstname);
    cout<<"Nhap ma don vi: ";
    in >> m.gID;
    cout<<"Nhap so dien thoai: ";
    in >> m.pnumber;
    cout<<"Nhap ngay/thang/nam sinh: "<<endl;
    cout<<"Nhap ngay sinh: ";
    in >> temp;
    m.ns.setDay(temp);
    cout<<"Nhap thang sinh: ";
    in >> temp;
    m.ns.setMonth(temp);
    cout<<"Nhap nam sinh: ";
    in >> temp;
    m.ns.setYear(temp);
    while(gt==0){
        gt=1; //điều kiện dừng
        cout<<"Nhap gioi tinh (nam/nu): ";
        in >> s;
        if(s=="nam") m.gender = 0;
        else if (s=="nu") m.gender = 1;
        else {
            cout<<"Ban da nhap sai!"<<endl;
            gt=0;
        }
    }
    cout<<"Nhap ma chuc vu: ";
    in >> m.position;
    cout<<"Nhap he so luong: ";
    in >> m.C_salary;
    cout<<"Nhap nam vao lam viec: ";
    in >> m.year_in;
    cout<<"Nhap trinh do cua nhan vien: ";
    getline(in>>ws,m.degree);
    cout<<"Nhap trinh do ngoai ngu cua nhan vien: ";
    getline(in>>ws,m.L_certificate);
    return in;
}

//don vi
class group { 
private:
    string gID;  //ma don vi
    string gName;
    string mID; //ma nhan vien
public:
    group(string ="", string ="", string ="");
    void readfile_G(ifstream &);
    void display();
    friend ostream &operator <<(ostream &out, const group&);
};

group::group(string gID, string gName, string mID)
    :gID(gID),gName(gName),mID(mID){}

void group::readfile_G(ifstream &in){
    getline(in,gID,'|');
    getline(in,gName,'|');
    getline(in,mID,'\n');
}

void group::display(){
    cout<<setw(10)<<gID<<setw(20)<<gName<<setw(10)<<mID<<endl;
}

ostream &operator <<(ostream &out, const group &g){
    out<<setw(10)<<g.gID<<setw(20)<<g.gName<<setw(10)<<g.mID<<endl;
    return out;
}

//chuc vu
class Position 
{
private:
    string pID;
    string pName; 
    float pAllowance;
public:
    Position(string ="", string ="", float =0);
    void readfile_P(ifstream &);
    void display();
    friend ostream &operator <<(ostream &out, const Position&);
};

Position::Position(string pID, string pName, float pAllowance)
    :pID(pID),pName(pName),pAllowance(pAllowance){}

void Position::readfile_P(ifstream &in){
    string s;
    getline(in,pID,'|');
    getline(in,pName,'|');
    in >> pAllowance;
    getline(in,s,'\n');
}

void Position::display(){
    cout<<setw(10)<<pID<<setw(20)<<pName<<setw(10)<<pAllowance<<endl;
}

ostream &operator <<(ostream &out, const Position &p){
    out<<setw(10)<<p.pID<<setw(20)<<p.pName<<setw(10)<<p.pAllowance<<endl;
    return out;
}

//danh sach
class list{
private:
    int numofMem;   //sl nv
    int numofGr;    //sl đơn vị
    int numofP;
    member *list_mem;
    group *list_gr;
    Position *list_p;
public:
    list(int = 0, int = 0, int = 0);
    list(const list&);
    ~list();
    void readfile_mem(ifstream& in);                 //nhap danh sach nhan vien tu file 
    void readfile_gr(ifstream& in);                  //nhap danh sach don vi tu file
    void readfile_p(ifstream& in);                   //Nhap danh sach chuc vu
    void display_mem();                              //in danh sach nhan vien
    void display_gr();                               //in bang thong ke theo don vi
    void display_p();                                //in bang thong ke cac chuc vu
    void add(member&, int k);                        //bo sung 1 doi tuong vao vi tri k bat ki
    void sort(bool CompFunc(member&, member&));      //sap xep danh sach nhan vien theo thu tu tang/giam
    member search(member&);                          //tim kiem 1 nhan vien
    void delete_mem(member&);                        //xoa 1 nhan vien bat ki
    member &operator [](int i) const;                //toan tu lay phan tu thu i [] trong danh sach nhan vien
    const list &operator =(const list &);
    friend ostream &operator <<(ostream &out,const list&);
};

//Khoi tao
list::list(int NMem, int NGr, int NP)
:numofMem(NMem),numofGr(NGr),numofP(NP)
{
    list_mem = new member [numofMem];
    list_gr = new group [numofGr];
    list_p = new Position [numofP];

}

list::list(const list &l){
    this->numofMem = l.numofMem;
    this->numofGr = l.numofGr;
    this->numofP = l.numofP;

    this->list_mem = new member [numofMem];
    this->list_gr = new group [numofGr];
    this->list_p = new Position [numofP];

    for(int i=0; i<numofMem; i++){
        this->list_mem[i] = l.list_mem[i];
    }
    for(int i=0; i<numofGr; i++){
        this->list_gr[i] = l.list_gr[i];
    }
    for(int i=0; i<numofP; i++){
        this->list_p[i] = l.list_p[i];
    }
}

list::~list(){
    delete [] list_mem; 
    delete [] list_gr;
    delete [] list_p;
}

//doc file nhan vien 
void list::readfile_mem(ifstream& in){
    in.open("Nhan Vien.txt", ios_base::in);
    string s;
    getline(in,s,'\n');
    int i=0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofMem+1;
        member* newArr = new member[newSize];
        for (int j = 0; j < numofMem; j++)
	        newArr[j] = list_mem[j];
        delete[] list_mem;
        numofMem=newSize;
        list_mem = newArr;
        //doc file
        list_mem[i].readfile_M(in);
        i++;
    } 
    in.close();
} 
//doc file don vi : ô kê nuôn 
void list::readfile_gr(ifstream& in){
    in.open("Don Vi.txt", ios_base::in);
    string s;
    getline(in,s,'\n');//bỏ dòng đầu
    int i=0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofGr+1;
        group* newArr = new group[newSize];
        for (int j = 0; j < numofGr; j++)
	        newArr[j] = list_gr[j];
        delete[] list_gr;
        list_gr = newArr;
        numofGr=newSize;
        //doc file
        list_gr[i].readfile_G(in);
        i++;
    }
    in.close();
} 

void list::readfile_p(ifstream& in){
    in.open("Chuc Vu.txt", ios_base::in);
    string s;
    getline(in,s,'\n');//bỏ dòng đầu    
    int i=0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofP+1;
        Position* newArr = new Position[newSize];
        for (int j = 0; j < numofP; j++)
	        newArr[j] = list_p[j];
        delete[] list_p;
        list_p = newArr;
        numofP=newSize;
        //doc file
        list_p[i].readfile_P(in);
        i++;
    }
    in.close();
} 

void list::display_mem(){
    for(int i=0; i<numofMem; i++){
        cout<<list_mem[i]<<endl;
    }
}

void list::display_gr(){
    for(int i=0; i<numofGr; i++){
        cout<<list_gr[i]<<endl;
    }
}

void list::display_p(){
    for(int i=0; i<numofP; i++){
        cout<<list_p[i]<<endl;
    }
}

int main(){
    cout <<left;
    list com;
    ifstream filein_M;
    com.readfile_mem(filein_M);
    ifstream filein_G;
    com.readfile_gr(filein_G);
    ifstream filein_p;
    com.readfile_p(filein_p);
    
    //com.display_mem();
    //com.display_gr();
    //com.display_p();

    member m;
    cin>>m;
    cout<<m;
    return 0;
}