#include <cmath>
#include <iostream>
#include <vector>

// Constants
constexpr float k_smallNumber = 1.0e-4f;
constexpr float k_pi = 3.1415927f;
constexpr float k_radPerDeg = k_pi/180.0f;
constexpr float k_degPerRad = 180.0f/k_pi;

// Returns true if the value is nearly equal to zero within k_smallNumber.
bool IsNearlyZero(const float x)
{
	return std::abs(x) <= k_smallNumber;
}

// Returns true if the two values are nearly equal within k_smallNumber.
bool IsNearlyEqual(const float x, const float y)
{
	return IsNearlyZero(x - y);
}

// Returns the square of x.
float Sqrd(const float x) { return x*x; }

// Converts x from degrees to radians and returns the result.
float DegToRad(const float x) { return x*k_radPerDeg; }

// Converts x from radians to degrees and returns the result.
float RadToDeg(const float x) { return x*k_degPerRad; }

// A simple 2D Euclidean vector.
class Vec2
{
public:
	// Default constructs this Vec2.
	Vec2() = default;

	// Constructs this Vec2 with x and y components.
	Vec2(const float x, const float y) : m_x{x}, m_y{y} {}

	// Constructs this Vec2 with a heading relative to the x-axis given in radians.
	explicit Vec2(const float heading) : m_x{std::cos(heading)}, m_y{std::sin(heading)} {}

	// Adds a Vec2 to this Vec2.
	Vec2& operator+=(const Vec2& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return *this;
	}

	// Subtracts a Vec2 from this Vec2.
	Vec2& operator-=(const Vec2& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		return *this;
	}

	// Multiplies this Vec2 by a scalar.
	Vec2& operator*=(const float s)
	{
		m_x *= s;
		m_y *= s;
		return *this;
	}

	// Divides this Vec2 by a scalar.
	Vec2& operator/=(const float s)
	{
		m_x /= s;
		m_y /= s;
		return *this;
	}

	// Returns the x component of this Vec2.
	float X() const { return m_x; }

	// Returns the y component of this Vec2.
	float Y() const { return m_y; }

	// Returns the square of the magnitude of this Vec2.
	float MagnitudeSqrd() const { return Sqrd(m_x)+ Sqrd(m_y); }

	// Returns the magnitude of this Vec2.
	float Magnitude() const { return std::sqrt(MagnitudeSqrd()); }

	// Normalizes this Vec2.
	// If this is a zero vector, it becomes a unit vector along the x-axis.
	Vec2& Normalize()
	{
		const auto magnitude = Magnitude();

		if (!IsNearlyZero(magnitude))
		{
			m_x /= magnitude;
			m_y /= magnitude;
		}
		else
		{
			m_x = 1.0f;
			m_y = 0.0f;
		}

		return *this;
	}

	// Returns the normal of this Vec2.
	Vec2 Normal() const { return Vec2(*this).Normalize(); }

	// Returns the dot product of this Vec2 and another.
	float Dot(const Vec2& other) const { return m_x*other.m_x + m_y*other.m_y; }

	// Returns the cross product of this Vec2 and another.
	float Cross(const Vec2& other) const { return m_x*other.m_y - m_y*other.m_x; }

private:
	float m_x = 0.0f;
	float m_y = 0.0f;
};

// Returns the result of adding one Vec2 to another.
Vec2 operator+(Vec2 lhs, const Vec2& rhs) { return lhs += rhs; }

// Returns the result of subtracting one Vec2 from another.
Vec2 operator-(Vec2 lhs, const Vec2& rhs) { return lhs -= rhs; }

// Returns the result of multiplying a Vec2 by a scalar.
Vec2 operator*(Vec2 lhs, const float s) { return lhs *= s; }

// Returns the result of dividing a Vec2 by a scalar.
Vec2 operator/(Vec2 lhs, const float s) { return lhs /= s; }

// Returns the square of the distance between two Vec2s.
float DistanceSqrd(const Vec2& v1, const Vec2& v2) { return (v1 - v2).MagnitudeSqrd(); }

// Returns the distance between two Vec2s.
float Distance(const Vec2& v1, const Vec2& v2) { return std::sqrt(DistanceSqrd(v1, v2)); }

// Returns the angle (in radians) between two Vec2s.
inline float AngleBetween(const Vec2& v1, const Vec2& v2)
{
	const Vec2 norm1 = v1.Normal();
	const Vec2 norm2 = v2.Normal();

	return std::atan2(norm1.Cross(norm2), norm1.Dot(norm2));
}


// A simple character representation.
class Character
{
public:
	// Default constructs this Character
	Character() = default;

	// Constructs this Character with a position and a heading off the x=axis given in radians.
	Character(const Vec2& position, const float heading) : m_position{position}, m_heading{heading} {}

	// Returns the position of this Character.
	const Vec2& GetPosition() const { return m_position; }

	// Returns the heading of this Character.
	float GetHeading() const { return m_heading; }

private:
	Vec2  m_position;
	float m_heading = 0.0f;
};


// A simple enemy representation.
class Enemy : public Character
{
public:
	// Default constructs this Enemy
	Enemy() = default;

	// Constructs this Enemy with a position, a heading off the x=axis given in radians,
	// a detection distance and a detection angle given in radians.
	Enemy(
		const Vec2& position,
		const float heading,
		const float detectionDistance,
		const float detectionAngle) :
		Character{position, heading},
		m_detectionDistance{detectionDistance},
		m_detectionAngle{detectionAngle}
	{}

	// Returns the player-detection distance of this Character.
	float GetDetectionDistance() const { return m_detectionDistance; }

	// Returns the player-detection angle of this Character.
	float GetDetectionAngle() const { return m_detectionAngle; }

private:
	float m_detectionDistance = 0.0f;
	float m_detectionAngle = 0.0f;
};


// Returns true if the player is detected by any of the enemies.
// [Provide the implementation of this function.]
bool IsPlayerDetected(const Character& player, const std::vector<Enemy>& enemies) {
    for (const auto& enemy : enemies) {

        // The goal is to get the dot product is greater than cos of the half detection angle
        // Which means the player is detected
        // Otherwise the player is not with in detection range

        auto distance = (player.GetPosition() - enemy.GetPosition()).Magnitude();

        if (distance <= enemy.GetDetectionDistance()) {
            (player.GetPosition() - enemy.GetPosition()).Normalize();
            Vec2 enemyHeadingVec(enemy.GetHeading());

            float dotProduct = enemyHeadingVec.Dot(player.GetPosition() - enemy.GetPosition());
            float cosHalfDetectionAngle = std::cos(enemy.GetDetectionAngle() / 2.0f);

            // Compare dot product with detection angle
            if (dotProduct >= cosHalfDetectionAngle) {
                return true;
            }
        }
    }

    return false;
}


// Tests the result of IsPlayerDetected() with the following parameters:
//
// Player position: (0.0f, 0.0f)
// Player heading : 0 degrees
// 
// Description: Player is at the origin with no enemies present.
//
// Expected result: false
bool Test1()
{
	const Character player{{0.0f, 0.0f}, DegToRad(0.0f)};

	const std::vector<Enemy> enemies;

	const bool bExpectedResult = false;

	return IsPlayerDetected(player, enemies) == bExpectedResult;
}

// Tests the result of IsPlayerDetected() with the following parameters:
//
// Player position: (0.0f, 0.0f)
// Player heading : 0 degrees
// 
// Enemy1 position          : (0.0f, 0.0f)
// Enemy1 detection distance: 0.0f
// Enemy1 detection angle   : 0 degrees
//
// Description: Player and enemy are at the origin. Enemy has zero detection distance and angle.
//
// Expected result: false
bool Test2()
{
	const Character player{{0.0f, 0.0f}, DegToRad(0.0f)};

	const std::vector<Enemy> enemies{
		{{0.0f, 0.0f}, 0.0f, 0.0f, DegToRad(0.0f)}};

	const bool bExpectedResult = false;

	return IsPlayerDetected(player, enemies) == bExpectedResult;
}

// Tests the result of IsPlayerDetected() with the following parameters:
//
// Player position: (1.0f, 0.0f)
// Player heading : 0 degrees
// 
// Enemy1 position          : (0.0f, 0.0f)
// Enemy1 detection distance: 10.0f
// Enemy1 detection angle   : 10 degrees
//
// Description: Player is directly in front of an enemy at the origin and inside its detection sector.
//
// Expected result: true
bool Test3()
{
	const Character player{{1.0f, 0.0f}, DegToRad(0.0f)};

	const std::vector<Enemy> enemies{
		{{0.0f, 0.0f}, 0.0f, 10.0f, DegToRad(10.0f)}};

	const bool bExpectedResult = true;

	return IsPlayerDetected(player, enemies) == bExpectedResult;
}

// [Provide more tests here if you'd like.]
bool Test4(){
    Character player({0, 0}, 0);
    std::vector<Enemy> enemies = {
            Enemy({10, 0}, 0, 15, DegToRad(60)),
            Enemy({-10, 0}, DegToRad(180), 15, DegToRad(60)),
            Enemy({0, 10}, DegToRad(90), 15, DegToRad(60)),
            Enemy({0, -10}, DegToRad(-90), 15, DegToRad(60))
    };

    const bool bExpectedResult = true;

    return IsPlayerDetected(player, enemies) == bExpectedResult;
}

int main()
{
	const auto bTest1Passed = Test1();
	const auto bTest2Passed = Test2();
	const auto bTest3Passed = Test3();
	// [Call additional tests here.]
    const auto bTest4Passed = Test4();

	std::cout << "Test 1: " << (bTest1Passed ? "passed" : "failed") << "\n";
	std::cout << "Test 2: " << (bTest2Passed ? "passed" : "failed") << "\n";
	std::cout << "Test 3: " << (bTest3Passed ? "passed" : "failed") << "\n";
	// [Output additional test results here.]

	return 0;
}
