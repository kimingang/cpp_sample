/* 01_cpp_coding_style */

/*
- The names of variables, functions, etc. follow the Hungarian notation.
Make it possible to know the data type by the prefix of the variable name. (refer to the table of prefixes below).

int nIntegerNumber;
double dFloatingPointNumber;
int fnInitializeDataset(const std::string& strFileName);

- A function name is a verb + object structure, such as Verb + Noun + Type or Specialized name.
Global general functions are written in Hungarian notation after appending fn subscript, and class member functions start with a lowercase letter except for fn.

bool fnInitDataSet(const DataSetType& DataSet); // initialize data set

class DataSetType {
public:
  bool initDataSet();
};

- Class and struct, which are user-defined data types, start with an uppercase letter and attach function object as a prefix to FO, and attach Type as a subscript for classes that are used as values.
Among the member variables of a class, protected or private that are not exposed to the outside are appended with _ as a subscript.

class DataType{
  int nID;
  std::string strName;
};
struct DataSetType{
  int nGroupIndex;
  std::vector<DataType> vecData;
private:
  int nAccessCount_;
};
class FODeleteElement{
public:
    void delete()(Object* obj);
}

- Macros and preprocessors are prefixed with namespace or project names.

 XXX_D_DATA // preprocessor constant variables :  XXX namespace + Define + Value name
  enum enumDATA_TYPE { eINT, eDOUBLE } // enumeration

- variable prefix
prefix	description
gv	    global variable
p	    pointer type
c	    signed char
uc	    unsigned char
wc	    wide char
s	    signed short
us	    unsigned short
n	    signed integer
un	    unsigned integer
l	    signed long
ul	    unsigned long
ll	    signed long long
f	    sigle floating number
d	    double floating number
vec	    vector
list	list
deq	    deque
map	    map
mmap	multi map
set	    set
mset	multi set
umap	unordered map
ummap	unordered multi map
uset	unordered set
umset	unordered multi set
sz	    char array, include null
wsz	    wide char array, include null
str	    std::string
wstr	std::wstring

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <typeinfo>

using namespace std;

#ifdef _DEBUG
#define SAMPLE_D_FUNC_INFO   cout << __FUNCTION__ << ':' << __LINE__ << ':' << __DATE__ << ' ' << __TIME__ << endl
#else
#define SAMPLE_D_FUNC_INFO
#endif

template <typename Container>
size_t fnPrintContainer(const Container& c, const char* str = "")
{
    SAMPLE_D_FUNC_INFO;
    cout << str << ':';
    for (const auto& val : c) {
        cout << val << ' ';
    }
    cout << endl;
    return c.size();
}

class DataType {
public:
    //! defalut constructor
    explicit DataType(int n = 0, const string& str = "") : nUserID_(n), strUserName_(str) {}
    //! member variables to string
    const string to_string() const
    {
        ostringstream oss;
        oss << nUserID_ << ',' << strUserName_;
        return oss.str();
    }

private:
    int nUserID_;       ///< User's ID
    string strUserName_;///< User's name
};

// operator<< overload for putting the DataType to ostream
std::ostream& operator<<(ostream& os, const DataType& data)
{
    os << data.to_string();
    return os;
}

int main()
{
    // list of int
    list<int> listInt = { 0,1,2,3,4,5,6,7,8,9 };
    // vector of int
    vector<int> vecInt = { 0,1,2,3,4,5,6,7,8,9 };
    // vector of DataType
    vector<DataType> vecData;
    vecData.emplace_back(1, "Steve");
    vecData.emplace_back(2, "Robert");
    vecData.emplace_back(3, "Michael");

    fnPrintContainer(listInt, typeid(listInt).name());
    fnPrintContainer(vecInt, typeid(vecInt).name());
    fnPrintContainer(vecData, typeid(vecData).name());

    return EXIT_SUCCESS;
}