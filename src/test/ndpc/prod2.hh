// C++ program generated by NDPC_gen_CXX
// 
//
// basic declarations

/*

  Basic base classes needed to interface with generated code

  We assume the following scalar types are available:

  int (and family), float (and family), string

*/


// basic collection type
// derive from this to create a custom interface
// 
// T must minimally support:
//     - operator= 
//
// operator[] must be fully parallel
//
// referencing past numitems should automatically expand
//
template <typename T> class Collection {
public: 
    Collection() {};
    Collection(int numitems) {} ;
    Collection(const Collection<T> &rhs) {} ;
    virtual ~Collection() {} ;

    
    virtual int numitems() const = 0;

    virtual Collection<T> & operator=(const Collection<T> &rhs) = 0;

    static struct OutOfBounds {} outofbounds;

    virtual T const & operator[](const int offset) const = 0;
    virtual T & operator[](const int offset) = 0;
};

int __attribute__ ((noinline)) prod2(Collection<int> &ret, Collection<int> &a, Collection<int> &b);






int __attribute__ ((noinline)) prod2(Collection<int> &ret, Collection<int> &a, Collection<int> &b)
{
 int __t0;
 int __t1;
 int __t2;
 { 
 int x;
 int __t3;
 int __t4;
 __t4 = a.numitems();
 // parallelize this!
 for (__t3 = 0; __t3 < __t4; __t3++) { 
  x = a[__t3];
if (ndpc_fork_preempt_thread()==ndpc_my_preempt_thread()) {
 { 
 int y;
 int __t5;
 int __t6;
 __t6 = b.numitems();
 // parallelize this!
 for (__t5 = 0; __t5 < __t6; __t5++) { 
  y = b[__t5];

 __t1 = x ;
__t2 = y ;
 __t0 = __t1 * __t2 ;
ret[__t3] = __t0;
}
}
return 0;
}
}
ndpc_join_child_preempt_threads();
}
  return 0;
}



// Done with code generation
