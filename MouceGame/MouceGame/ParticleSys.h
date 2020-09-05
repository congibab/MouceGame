#pragma once
# include <Siv3D.hpp>

struct Particle
{
	Vec2 start;
	Vec2 velocity;
};

struct Spark : IEffect
{
	Array<Particle> m_particles;

	Spark(const Vec2& start) : m_particles(5)
	{
		for (auto& particle : m_particles)
		{
			particle.start = start + RandomVec2(10.0);
			particle.velocity = RandomVec2(1.0) * Random(80.0);
		}
		
	}

	bool update(double t) override
	{
		for (const auto& particle : m_particles)
		{
			const Vec2 pos = particle.start + particle.velocity * t + 0.5 * t * t * Vec2(0, 240);
			Shape2D::Star(20, pos, pos.x * 5_deg).draw(HSV(pos.y - 40).toColorF(1.0 - t));
			//Triangle(pos, 16.0, pos.x * 5_deg).draw(HSV(pos.y - 40).toColorF(1.0 - t));
		}
		return t < 1.0;
	}
};

struct NumberEffect : IEffect
{
	Vec2 m_start;

	int32 m_number;

	Font m_font;

	NumberEffect(const Vec2& start, int32 num, const Font& font)
		: m_start(start)
		, m_number(num)
		, m_font(font) {}

	bool update(double t) override
	{
		const HSV color(180 - m_number * 1.8, 1.0 - (t * 2.0));

		m_font(m_number).drawAt(m_start.movedBy(0, t * -120), color);

		return t < 0.5;
	}
};

class ParticleSys
{
	
};

