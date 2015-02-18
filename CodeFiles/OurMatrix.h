template<class T>
class OurMatrix {
public:
	OurMatrix();
	OurMatrix(int nr, int nc);
	OurMatrix(DEMDimensionType, const T[]);
	OurMatrix(DEMDimensionType, const std::vector<T>);
	OurMatrix(int nr, int nc, const std::vector<T>);
	explicit OurMatrix(int nr, int nc, T defaultValue);
	OurMatrix(const OurMatrix<T>& a);
	~OurMatrix();
	OurMatrix<T>& operator=(const OurMatrix<T> & a);
	OurMatrix<double> toDouble() const;
	bool operator==(const OurMatrix<T>& a) const;
	bool operator!=(const OurMatrix<T>& a) const;

	const T& getElement(int i, int j) const;
	void setElement(const T& value, int i, int j);
	bool sumMatrix(const OurMatrix<T>& a);
	bool sumMatrix(const T& a);
	bool productMatrixElByEl(const OurMatrix<T>& a);
	bool productMatrixElByEl(const T& a);
	bool squareRootElByEl(); // only if T is a float or double
	bool powerElByEl(int power);
	T sumAll();
	double meanOfEls();
	double varianceOfEls();
	DEMDimensionType getDimension() const;
#ifdef DEBUG
	void printMatrix() const
#endif
private:
	T* data;
	long int nr;
	long int nc;
	long int numberOfZero;
	bool checkDimension(const OurMatrix<T>& a);
};

namespace OurMatrixInternal {
// square root element by element - partial specialization outside class scope
template<class T> inline bool squareRootElByEl_part(OurMatrix<T>& a);
template<> inline bool squareRootElByEl_part<double>(OurMatrix<double>& a);
template<class T> inline OurMatrix<double> toDouble(const OurMatrix<T>& a);
template<> inline OurMatrix<double> toDouble<double>(const OurMatrix<double>& a);
}
