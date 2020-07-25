#pragma once
#include <RayTracerLib/Math.h>

namespace RayTracer {
	/**
	 * @brief Represents a Color value (RGB)
	 */
	class Color {
	public:
		/**
		 * @brief Default constructor, sets all color values to 0
		 */
		Color();

		/**
		 * @brief Construct a Color from values
		 * @param r The red value
		 * @param g The green value
		 * @param b The blue value
		 */
		Color(double r, double g, double b);

		/**
		 * @brief Set red channel
		 * @param r The new red value
		 */
		void setRed(double r);

		/**
		 * @brief Set green channel
		 * @param g The new red value
		 */
		void setGreen(double g);

		/**
		 * @brief Set blue channel
		 * @param b The new red value
		 */
		void setBlue(double b);

		/**
		 * @brief Returns a vector of the three values
		 * @return The vector
		 */
		V3D getColorVector() const;

		/**
		 * @brief Get red value
		 * @return The red value
		 */
		double getRed() const;

		/**
		 * @brief Get green value
		 * @return The green value
		 */
		double getGreen() const;

		/**
		 * @brief Get blue value
		 * @return The blue value
		 */
		double getBlue() const;

		/**
		 * @brief Add two colors together
		 * @param other The other Color to add to this one
		 * @return Reference to this color
		 */
		Color& operator+(const Color& other);

		/**
		 * @brief Multiply two colors together
		 * @param other The other Color to mulitply into this one
		 * @return Reference to this color
		 */
		Color& operator*(const Color& other);

		/**
		 * @brief Multiply two colors together
		 * @param other The other Color to mulitply into this one
		 * @return Reference to this color
		 */
		Color& operator*(const V3D& other);

		friend Color operator*(const Color& color, double factor);

	private:
		double r = 0.0; ///< Red value
		double g = 0.0; ///< Green value
		double b = 0.0; ///< Blue value
	};

	/**
	 * @brief Multiply a factor into a color and returns a new color
	 * @param color The color to be used
	 * @param factor The factor to be used
	 * @return A new Color with color * factor on each channel
	 */
	Color operator*(const Color& color, double factor);
};