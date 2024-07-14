#ifndef CONEPRIMITIVESHAPE_HEADER
#define CONEPRIMITIVESHAPE_HEADER
#include "BitmapPrimitiveShape.h"
#include "Cone.h"
#include "LevMarFunc.h"

#ifndef DLL_LINKAGE
#define DLL_LINKAGE
#endif

class DLL_LINKAGE ConePrimitiveShape
: public BitmapPrimitiveShape
{
public:
	size_t Identifier() const override;
	unsigned int RequiredSamples() const override { return Cone::RequiredSamples; }
	ConePrimitiveShape(const Cone &cone, float maxRadius = std::numeric_limits<float>::infinity(), float maxAngle = std::numeric_limits<float>::infinity(), float maxLength = std::numeric_limits<float>::infinity());
	PrimitiveShape* Clone() const override;						  
	float Distance(const Vec3f &p) const override;
	float SignedDistance(const Vec3f &p) const override;
	float NormalDeviation(const Vec3f &p, const Vec3f &n) const override;
	void DistanceAndNormalDeviation(const Vec3f &p,
		const Vec3f &n, std::pair< float, float > *dn) const override;
	void Project(const Vec3f &p, Vec3f *pp) const override;
	void Normal(const Vec3f &p, Vec3f *n) const override;
	unsigned int ConfidenceTests(unsigned int numTests, float epsilon,
		float normalThresh, float rms, const PointCloud &pc,
		const std::vector< size_t > &indices) const override;
	void Description(std::string *s) const override;
	bool Fit(const PointCloud &pc, float epsilon, float normalThresh,
		std::vector< size_t >::const_iterator begin,
		std::vector< size_t >::const_iterator end) override;
	PrimitiveShape *LSFit(const PointCloud &pc, float epsilon,
		float normalThresh,
		std::vector< size_t >::const_iterator begin,
		std::vector< size_t >::const_iterator end,
		std::pair< size_t, float > *score) const override;
	LevMarFunc< float > *SignedDistanceFunc() const override;
	void Serialize(std::ostream *o, bool binary = true) const override;
	size_t SerializedSize() const override;
	virtual void Serialize(float* array) const override {m_cone.Serialize(array);}
	virtual size_t SerializedFloatSize() const override {return m_cone.SerializedFloatSize();}		
	void Transform(float scale, const Vec3f &translate) override;
	void Transform(const GfxTL::MatrixXX< 3, 3, float > &rot,
		const GfxTL::Vector3Df &trans);
	void Visit(PrimitiveShapeVisitor *visitor) const override;
	void SuggestSimplifications(const PointCloud &pc,
		float distThresh,
		std::vector< std::shared_ptr< PrimitiveShape > > *suggestions) const override;
	bool Similar(float tolerance, const ConePrimitiveShape &shape) const;
	const Cone &Internal() const { return m_cone; }

	void Parameters(const Vec3f &p,
		std::pair< float, float > *param) const override;
	void Parameters(GfxTL::IndexedIterator< std::vector< size_t >::iterator,
			PointCloud::const_iterator > begin,
		GfxTL::IndexedIterator< std::vector< size_t >::iterator,
			PointCloud::const_iterator > end,
		std::vector< std::pair< float, float > > *bmpParams) const override;
	void Parameters(GfxTL::IndexedIterator< IndexIterator,
			PointCloud::const_iterator > begin,
		GfxTL::IndexedIterator< IndexIterator,
			PointCloud::const_iterator > end,
		std::vector< std::pair< float, float > > *bmpParams) const override;
	bool InSpace(float u, float v, Vec3f *p, Vec3f *n) const override;
	void BitmapExtent(float epsilon,
		GfxTL::AABox< GfxTL::Vector2Df > *bbox,
		std::vector< std::pair< float, float > > *params,
		size_t *uextent, size_t *vextent) override;
	void InBitmap(const std::pair< float, float > &param, float epsilon,
		const GfxTL::AABox< GfxTL::Vector2Df > &bbox, size_t uextent,
		size_t vextent, std::pair< int, int > *inBmp) const override;
	void PreWrapBitmap(const GfxTL::AABox< GfxTL::Vector2Df > &bbox,
		float epsilon, size_t uextent, size_t vextent,
		std::vector< char > *bmp) const override;
	void WrapBitmap(const GfxTL::AABox< GfxTL::Vector2Df > &bbox,
		float epsilon, bool *uwrap, bool *vwrap) const override;
	void WrapComponents(const GfxTL::AABox< GfxTL::Vector2Df > &bbox,
		float epsilon, size_t uextent, size_t vextent,
		std::vector< int > *componentImg,
		std::vector< std::pair< int, size_t > > *labels) const override;
	void SetExtent(const GfxTL::AABox< GfxTL::Vector2Df > &bbox,
		const std::vector< int > &componentsImg, size_t uextent,
		size_t vextent, float epsilon, int label);
	void SetExtent(const GfxTL::AABox< GfxTL::Vector2Df > &bbox);
	bool InSpace(size_t u, size_t v, float epsilon,
		const GfxTL::AABox< GfxTL::Vector2Df > &bbox, size_t uextent,
		size_t vextent, Vec3f *p, Vec3f *n) const override;
	bool CheckGeneratedShapeWithinLimits(const PointCloud& pc,
		std::vector< size_t >::const_iterator begin,
		std::vector< size_t >::const_iterator end) override
	{
		if (m_cone.RadiusAtLength(m_extBbox.Min()[0]) <= m_maxRadius &&
			m_cone.RadiusAtLength(m_extBbox.Max()[0]) <= m_maxRadius &&
			m_cone.RadiusAtLength(m_extBbox.Min()[1]) <= m_maxRadius &&
			m_cone.RadiusAtLength(m_extBbox.Max()[1]) <= m_maxRadius &&
			m_cone.Angle() <= m_maxAngle)
		{
			return true;
		}
		return false;
	}

private:
	template< class IteratorT >
	void ParametersImpl(IteratorT begin, IteratorT end,
		std::vector< std::pair< float, float > > *bmpParams) const;

private:
	Cone m_cone;
	float m_maxRadius;
	float m_maxLength;
	float m_maxAngle;
};

template< class IteratorT >
void ConePrimitiveShape::ParametersImpl(IteratorT begin, IteratorT end,
	std::vector< std::pair< float, float > > *bmpParams) const
{
	bmpParams->resize(end - begin);
	size_t j = 0;
	for(IteratorT i = begin; i != end; ++i, ++j)
		m_cone.Parameters(*i, &(*bmpParams)[j]);
	if(m_cone.Angle() < float(M_PI / 4)) // angle of cone less than 45 degrees
	{
		for(size_t j = 0; j < bmpParams->size(); ++j)
		{
			float r = m_cone.RadiusAtLength((*bmpParams)[j].first);
			// convert to arc length and centralize
			(*bmpParams)[j].second = ((*bmpParams)[j].second - float(M_PI)) * r;
		}
	}
	else
	{
		for(size_t j = 0; j < bmpParams->size(); ++j)
		{
			float l = (*bmpParams)[j].first;
			(*bmpParams)[j].first = std::sin((*bmpParams)[j].second) * l;
			(*bmpParams)[j].second = std::cos((*bmpParams)[j].second) * l;
		}
	}
}

class DLL_LINKAGE ConeLevMarFunc
: public LevMarFunc< float >
{
public:
	ConeLevMarFunc(const Cone &c)
	: m_cone(c)
	{}

	float operator()(const float *x) const
	{
		return m_cone.SignedDistance(*((const Vec3f *)x));
	}

	void operator()(const float *x, float *gradient) const
	{
		m_cone.Normal(*((const Vec3f *)x), (Vec3f *)gradient);
	}

private:
	Cone m_cone;
};

#endif
