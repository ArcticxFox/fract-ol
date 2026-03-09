*This project has been created as part of the 42 curriculum by ejones*

# FRACT'OL

- ## 1. Description

	Fractol is a graphical project that visualizes mathematical fractals in real-time using the MiniLibX library. It allows users to explore complex mathematical structures interactively, including zooming and panning, to discover the intricate patterns of fractals.

	**Features:**

	**1. Mandelbrot Set**
	- Classic fractal defined by iterative complex number calculations.
	- Users can zoom in/out and explore the infinite detail.

	**2. Julia Set**
	- A variation of the Mandelbrot set where each fractal is defined by a constant complex number.
	- Parameters are adjustable at runtime for dynamic exploration.

	**3. Koch Snowflake**
	- A geometric fractal built recursively from a triangle.
	- Recursion depth adjustable to increase complexity.

	**4. Interactive Controls**
	- Zoom in/out with mouse wheel.
	- Move the view using arrow keys.
	- Adjust iteration depth or parameters in real-time.

- ## 2. Instructions

	- ### 2.1 Makefile commands

		make - to compile \
		make bonus - to compile bonuses \
		make clean - to remove object files \
		make fclean - uses clean, then removes libraries \
		make re - uses fclean, and recompiles th whole project

	- ### 2.2 Execution
		```./fractol mandelbrot```\
		```./fractol mandelbrot <precision optional>```\
		```./fractol julia <const RE> <const Im> <precision optional>```\
		```./fractol_bonus koch```
	Julia sets
	```
	./fractol julia 0.25 0.5
	./fractol julia 0.285 0.013
	./fractol julia 0.285 0.5
	./fractol julia 0.3 0.5
	./fractol julia -1.417022285618 0.0099534
	./fractol julia -0.4 0.6
	```

- ## Resources
	links :
	- [fractols](https://zestedesavoir.com/tutoriels/329/dessiner-la-fractale-de-mandelbrot/)
	- [julia sets](https://fr.wikipedia.org/wiki/Ensemble_de_Julia)
	- [LibX guide](https://harm-smits.github.io/42docs/libs/minilibx)
	- [README formatting syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

	ChatGPT was used to get the algo of **KOCH** fractol for bonus.
