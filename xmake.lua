add_requires("libsdl")
add_requires("libsdl_image")
add_requires("libsdl_ttf")
add_requires("libsdl_gfx")

target("PoloGame")
  set_kind("binary")
  set_languages("c++20")

  add_files("src/*.cpp")
    add_files("src/levels/*.cpp")
  add_headerfiles("src/*.hpp")
  add_headerfiles("src/levels/*.hpp")

  add_packages("libsdl")
  add_packages("libsdl_image")
  add_packages("libsdl_ttf")
  add_packages("libsdl_gfx")
  set_rundir("/")

  