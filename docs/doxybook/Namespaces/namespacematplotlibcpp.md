---
title: matplotlibcpp

---

# matplotlibcpp



## Namespaces

| Name           |
| -------------- |
| **[matplotlibcpp::detail](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp_1_1detail/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[matplotlibcpp::Plot](/cpp_robotics_core/doxybook/Classes/classmatplotlibcpp_1_1Plot/)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[backend](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-backend)**(const std::string & name) |
| bool | **[annotate](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-annotate)**(std::string annotation, double x, double y) |
| template <typename Numeric \> <br>bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**(const std::vector< Numeric > & x, const std::vector< Numeric > & y, const std::map< std::string, std::string > & keywords) |
| template <typename Numeric \> <br>void | **[plot_surface](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot-surface)**(const std::vector<::std::vector< Numeric >> & x, const std::vector<::std::vector< Numeric >> & y, const std::vector<::std::vector< Numeric >> & z, const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >(), const long fig_number =0) |
| template <typename Numeric \> <br>void | **[contour](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-contour)**(const std::vector<::std::vector< Numeric >> & x, const std::vector<::std::vector< Numeric >> & y, const std::vector<::std::vector< Numeric >> & z, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>void | **[spy](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-spy)**(const std::vector<::std::vector< Numeric >> & x, const double markersize =-1, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>void | **[plot3](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot3)**(const std::vector< Numeric > & x, const std::vector< Numeric > & y, const std::vector< Numeric > & z, const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >(), const long fig_number =0) |
| template <typename Numeric \> <br>bool | **[stem](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-stem)**(const std::vector< Numeric > & x, const std::vector< Numeric > & y, const std::map< std::string, std::string > & keywords) |
| template <typename Numeric \> <br>bool | **[fill](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-fill)**(const std::vector< Numeric > & x, const std::vector< Numeric > & y, const std::map< std::string, std::string > & keywords) |
| template <typename Numeric \> <br>bool | **[fill_between](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-fill-between)**(const std::vector< Numeric > & x, const std::vector< Numeric > & y1, const std::vector< Numeric > & y2, const std::map< std::string, std::string > & keywords) |
| template <typename Numeric \> <br>bool | **[arrow](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-arrow)**(Numeric x, Numeric y, Numeric end_x, Numeric end_y, const std::string & fc ="r", const std::string ec ="k", Numeric head_length =0.25, Numeric head_width =0.1625) |
| template <typename Numeric \> <br>bool | **[hist](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-hist)**(const std::vector< Numeric > & y, long bins =10, std::string color ="b", double alpha =1.0, bool cumulative =false) |
| void | **[imshow](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-imshow)**(const unsigned char * ptr, const int rows, const int columns, const int colors, const std::map< std::string, std::string > & keywords ={}, PyObject ** out =nullptr) |
| void | **[imshow](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-imshow)**(const float * ptr, const int rows, const int columns, const int colors, const std::map< std::string, std::string > & keywords ={}, PyObject ** out =nullptr) |
| template <typename NumericX ,typename NumericY \> <br>bool | **[scatter](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-scatter)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const double s =1.0, const std::map< std::string, std::string > & keywords ={}) |
| template <typename NumericX ,typename NumericY ,typename NumericColors \> <br>bool | **[scatter_colored](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-scatter-colored)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::vector< NumericColors > & colors, const double s =1.0, const std::map< std::string, std::string > & keywords ={}) |
| template <typename NumericX ,typename NumericY ,typename NumericZ \> <br>bool | **[scatter](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-scatter)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::vector< NumericZ > & z, const double s =1.0, const std::map< std::string, std::string > & keywords ={}, const long fig_number =0) |
| template <typename Numeric \> <br>bool | **[boxplot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-boxplot)**(const std::vector< std::vector< Numeric >> & data, const std::vector< std::string > & labels ={}, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>bool | **[boxplot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-boxplot)**(const std::vector< Numeric > & data, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>bool | **[bar](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-bar)**(const std::vector< Numeric > & x, const std::vector< Numeric > & y, std::string ec ="black", std::string ls ="-", double lw =1.0, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>bool | **[bar](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-bar)**(const std::vector< Numeric > & y, std::string ec ="black", std::string ls ="-", double lw =1.0, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>bool | **[barh](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-barh)**(const std::vector< Numeric > & x, const std::vector< Numeric > & y, std::string ec ="black", std::string ls ="-", double lw =1.0, const std::map< std::string, std::string > & keywords ={ }) |
| bool | **[subplots_adjust](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-subplots-adjust)**(const std::map< std::string, double > & keywords ={}) |
| template <typename Numeric \> <br>bool | **[named_hist](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-named-hist)**(std::string label, const std::vector< Numeric > & y, long bins =10, std::string color ="b", double alpha =1.0) |
| template <typename NumericX ,typename NumericY \> <br>bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & s ="") |
| template <typename NumericX ,typename NumericY ,typename NumericZ \> <br>bool | **[contour](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-contour)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::vector< NumericZ > & z, const std::map< std::string, std::string > & keywords ={}) |
| template <typename NumericX ,typename NumericY ,typename NumericU ,typename NumericW \> <br>bool | **[quiver](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-quiver)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::vector< NumericU > & u, const std::vector< NumericW > & w, const std::map< std::string, std::string > & keywords ={}) |
| template <typename NumericX ,typename NumericY ,typename NumericZ ,typename NumericU ,typename NumericW ,typename NumericV \> <br>bool | **[quiver](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-quiver)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::vector< NumericZ > & z, const std::vector< NumericU > & u, const std::vector< NumericW > & w, const std::vector< NumericV > & v, const std::map< std::string, std::string > & keywords ={}) |
| template <typename NumericX ,typename NumericY \> <br>bool | **[stem](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-stem)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & s ="") |
| template <typename NumericX ,typename NumericY \> <br>bool | **[semilogx](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-semilogx)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & s ="") |
| template <typename NumericX ,typename NumericY \> <br>bool | **[semilogy](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-semilogy)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & s ="") |
| template <typename NumericX ,typename NumericY \> <br>bool | **[loglog](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-loglog)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & s ="") |
| template <typename NumericX ,typename NumericY \> <br>bool | **[errorbar](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-errorbar)**(const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::vector< NumericX > & yerr, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>bool | **[named_plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-named-plot)**(const std::string & name, const std::vector< Numeric > & y, const std::string & format ="") |
| template <typename NumericX ,typename NumericY \> <br>bool | **[named_plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-named-plot)**(const std::string & name, const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & format ="") |
| template <typename NumericX ,typename NumericY \> <br>bool | **[named_semilogx](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-named-semilogx)**(const std::string & name, const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & format ="") |
| template <typename NumericX ,typename NumericY \> <br>bool | **[named_semilogy](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-named-semilogy)**(const std::string & name, const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & format ="") |
| template <typename NumericX ,typename NumericY \> <br>bool | **[named_loglog](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-named-loglog)**(const std::string & name, const std::vector< NumericX > & x, const std::vector< NumericY > & y, const std::string & format ="") |
| template <typename Numeric \> <br>bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**(const std::vector< Numeric > & y, const std::string & format ="") |
| template <typename Numeric \> <br>bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**(const std::vector< Numeric > & y, const std::map< std::string, std::string > & keywords) |
| template <typename Numeric \> <br>bool | **[stem](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-stem)**(const std::vector< Numeric > & y, const std::string & format ="") |
| template <typename Numeric \> <br>void | **[text](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-text)**(Numeric x, Numeric y, const std::string & s ="") |
| void | **[colorbar](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-colorbar)**(PyObject * mappable =NULL, const std::map< std::string, float > & keywords ={}) |
| long | **[figure](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-figure)**(long number =-1) |
| bool | **[fignum_exists](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-fignum-exists)**(long number) |
| void | **[figure_size](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-figure-size)**(size_t w, size_t h) |
| void | **[legend](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-legend)**() |
| void | **[legend](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-legend)**(const std::map< std::string, std::string > & keywords) |
| template <typename Numeric \> <br>void | **[set_aspect](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-set-aspect)**(Numeric ratio) |
| void | **[set_aspect_equal](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-set-aspect-equal)**() |
| template <typename Numeric \> <br>void | **[ylim](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-ylim)**(Numeric left, Numeric right) |
| template <typename Numeric \> <br>void | **[xlim](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-xlim)**(Numeric left, Numeric right) |
| std::array< double, 2 > | **[xlim](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-xlim)**() |
| std::array< double, 2 > | **[ylim](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-ylim)**() |
| template <typename Numeric \> <br>void | **[xticks](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-xticks)**(const std::vector< Numeric > & ticks, const std::vector< std::string > & labels ={}, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>void | **[xticks](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-xticks)**(const std::vector< Numeric > & ticks, const std::map< std::string, std::string > & keywords) |
| template <typename Numeric \> <br>void | **[yticks](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-yticks)**(const std::vector< Numeric > & ticks, const std::vector< std::string > & labels ={}, const std::map< std::string, std::string > & keywords ={}) |
| template <typename Numeric \> <br>void | **[yticks](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-yticks)**(const std::vector< Numeric > & ticks, const std::map< std::string, std::string > & keywords) |
| template <typename Numeric \> <br>void | **[margins](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-margins)**(Numeric margin) |
| template <typename Numeric \> <br>void | **[margins](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-margins)**(Numeric margin_x, Numeric margin_y) |
| void | **[tick_params](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-tick-params)**(const std::map< std::string, std::string > & keywords, const std::string axis ="both") |
| void | **[subplot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-subplot)**(long nrows, long ncols, long plot_number) |
| void | **[subplot2grid](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-subplot2grid)**(long nrows, long ncols, long rowid =0, long colid =0, long rowspan =1, long colspan =1) |
| void | **[title](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-title)**(const std::string & titlestr, const std::map< std::string, std::string > & keywords ={}) |
| void | **[suptitle](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-suptitle)**(const std::string & suptitlestr, const std::map< std::string, std::string > & keywords ={}) |
| void | **[axis](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-axis)**(const std::string & axisstr) |
| void | **[axhline](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-axhline)**(double y, double xmin =0., double xmax =1., const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >()) |
| void | **[axvline](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-axvline)**(double x, double ymin =0., double ymax =1., const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >()) |
| void | **[axvspan](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-axvspan)**(double xmin, double xmax, double ymin =0., double ymax =1., const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >()) |
| void | **[xlabel](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-xlabel)**(const std::string & str, const std::map< std::string, std::string > & keywords ={}) |
| void | **[ylabel](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-ylabel)**(const std::string & str, const std::map< std::string, std::string > & keywords ={}) |
| void | **[set_zlabel](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-set-zlabel)**(const std::string & str, const std::map< std::string, std::string > & keywords ={}) |
| void | **[grid](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-grid)**(bool flag, std::string which ="major", std::string axis ="both") |
| void | **[show](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-show)**(const bool block =true) |
| void | **[close](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-close)**() |
| void | **[xkcd](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-xkcd)**() |
| void | **[draw](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-draw)**() |
| template <typename Numeric \> <br>void | **[pause](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-pause)**(Numeric interval) |
| void | **[save](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-save)**(const std::string & filename, const int dpi =0) |
| void | **[rcparams](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-rcparams)**(const std::map< std::string, std::string > & keywords ={}) |
| void | **[clf](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-clf)**() |
| void | **[cla](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-cla)**() |
| void | **[ion](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-ion)**() |
| std::vector< std::array< double, 2 > > | **[ginput](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-ginput)**(const int numClicks =1, const std::map< std::string, std::string > & keywords ={}) |
| void | **[tight_layout](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-tight-layout)**() |
| template <typename... Args\> <br>bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**() |
| template <typename A ,typename B ,typename... Args\> <br>bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**(const A & a, const B & b, const std::string & format, Args... args) |
| bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**(const std::vector< double > & x, const std::vector< double > & y, const std::string & format ="") |
| bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**(const std::vector< double > & y, const std::string & format ="") |
| bool | **[plot](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp/#function-plot)**(const std::vector< double > & x, const std::vector< double > & y, const std::map< std::string, std::string > & keywords) |


## Functions Documentation

### function backend

```cpp
inline void backend(
    const std::string & name
)
```


Select the backend

**NOTE:** This must be called before the first plot command to have any effect.

Mainly useful to select the non-interactive 'Agg' backend when running matplotlibcpp in headless mode, for example on a machine with no display.

See also: [https://matplotlib.org/2.0.2/api/matplotlib_configuration_api.html#matplotlib.use](https://matplotlib.org/2.0.2/api/matplotlib_configuration_api.html#matplotlib.use)


### function annotate

```cpp
inline bool annotate(
    std::string annotation,
    double x,
    double y
)
```


### function plot

```cpp
template <typename Numeric >
bool plot(
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y,
    const std::map< std::string, std::string > & keywords
)
```


[Plot](/cpp_robotics_core/doxybook/Classes/classmatplotlibcpp_1_1Plot/) a line through the given x and y data points..

See: [https://matplotlib.org/3.2.1/api/_as_gen/matplotlib.pyplot.plot.html](https://matplotlib.org/3.2.1/api/_as_gen/matplotlib.pyplot.plot.html)


### function plot_surface

```cpp
template <typename Numeric >
void plot_surface(
    const std::vector<::std::vector< Numeric >> & x,
    const std::vector<::std::vector< Numeric >> & y,
    const std::vector<::std::vector< Numeric >> & z,
    const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >(),
    const long fig_number =0
)
```


### function contour

```cpp
template <typename Numeric >
void contour(
    const std::vector<::std::vector< Numeric >> & x,
    const std::vector<::std::vector< Numeric >> & y,
    const std::vector<::std::vector< Numeric >> & z,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function spy

```cpp
template <typename Numeric >
void spy(
    const std::vector<::std::vector< Numeric >> & x,
    const double markersize =-1,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function plot3

```cpp
template <typename Numeric >
void plot3(
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y,
    const std::vector< Numeric > & z,
    const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >(),
    const long fig_number =0
)
```


### function stem

```cpp
template <typename Numeric >
bool stem(
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y,
    const std::map< std::string, std::string > & keywords
)
```


### function fill

```cpp
template <typename Numeric >
bool fill(
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y,
    const std::map< std::string, std::string > & keywords
)
```


### function fill_between

```cpp
template <typename Numeric >
bool fill_between(
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y1,
    const std::vector< Numeric > & y2,
    const std::map< std::string, std::string > & keywords
)
```


### function arrow

```cpp
template <typename Numeric >
bool arrow(
    Numeric x,
    Numeric y,
    Numeric end_x,
    Numeric end_y,
    const std::string & fc ="r",
    const std::string ec ="k",
    Numeric head_length =0.25,
    Numeric head_width =0.1625
)
```


### function hist

```cpp
template <typename Numeric >
bool hist(
    const std::vector< Numeric > & y,
    long bins =10,
    std::string color ="b",
    double alpha =1.0,
    bool cumulative =false
)
```


### function imshow

```cpp
inline void imshow(
    const unsigned char * ptr,
    const int rows,
    const int columns,
    const int colors,
    const std::map< std::string, std::string > & keywords ={},
    PyObject ** out =nullptr
)
```


### function imshow

```cpp
inline void imshow(
    const float * ptr,
    const int rows,
    const int columns,
    const int colors,
    const std::map< std::string, std::string > & keywords ={},
    PyObject ** out =nullptr
)
```


### function scatter

```cpp
template <typename NumericX ,
typename NumericY >
bool scatter(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const double s =1.0,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function scatter_colored

```cpp
template <typename NumericX ,
typename NumericY ,
typename NumericColors >
bool scatter_colored(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::vector< NumericColors > & colors,
    const double s =1.0,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function scatter

```cpp
template <typename NumericX ,
typename NumericY ,
typename NumericZ >
bool scatter(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::vector< NumericZ > & z,
    const double s =1.0,
    const std::map< std::string, std::string > & keywords ={},
    const long fig_number =0
)
```


### function boxplot

```cpp
template <typename Numeric >
bool boxplot(
    const std::vector< std::vector< Numeric >> & data,
    const std::vector< std::string > & labels ={},
    const std::map< std::string, std::string > & keywords ={}
)
```


### function boxplot

```cpp
template <typename Numeric >
bool boxplot(
    const std::vector< Numeric > & data,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function bar

```cpp
template <typename Numeric >
bool bar(
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y,
    std::string ec ="black",
    std::string ls ="-",
    double lw =1.0,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function bar

```cpp
template <typename Numeric >
bool bar(
    const std::vector< Numeric > & y,
    std::string ec ="black",
    std::string ls ="-",
    double lw =1.0,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function barh

```cpp
template <typename Numeric >
bool barh(
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y,
    std::string ec ="black",
    std::string ls ="-",
    double lw =1.0,
    const std::map< std::string, std::string > & keywords ={ }
)
```


### function subplots_adjust

```cpp
inline bool subplots_adjust(
    const std::map< std::string, double > & keywords ={}
)
```


### function named_hist

```cpp
template <typename Numeric >
bool named_hist(
    std::string label,
    const std::vector< Numeric > & y,
    long bins =10,
    std::string color ="b",
    double alpha =1.0
)
```


### function plot

```cpp
template <typename NumericX ,
typename NumericY >
bool plot(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & s =""
)
```


### function contour

```cpp
template <typename NumericX ,
typename NumericY ,
typename NumericZ >
bool contour(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::vector< NumericZ > & z,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function quiver

```cpp
template <typename NumericX ,
typename NumericY ,
typename NumericU ,
typename NumericW >
bool quiver(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::vector< NumericU > & u,
    const std::vector< NumericW > & w,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function quiver

```cpp
template <typename NumericX ,
typename NumericY ,
typename NumericZ ,
typename NumericU ,
typename NumericW ,
typename NumericV >
bool quiver(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::vector< NumericZ > & z,
    const std::vector< NumericU > & u,
    const std::vector< NumericW > & w,
    const std::vector< NumericV > & v,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function stem

```cpp
template <typename NumericX ,
typename NumericY >
bool stem(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & s =""
)
```


### function semilogx

```cpp
template <typename NumericX ,
typename NumericY >
bool semilogx(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & s =""
)
```


### function semilogy

```cpp
template <typename NumericX ,
typename NumericY >
bool semilogy(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & s =""
)
```


### function loglog

```cpp
template <typename NumericX ,
typename NumericY >
bool loglog(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & s =""
)
```


### function errorbar

```cpp
template <typename NumericX ,
typename NumericY >
bool errorbar(
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::vector< NumericX > & yerr,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function named_plot

```cpp
template <typename Numeric >
bool named_plot(
    const std::string & name,
    const std::vector< Numeric > & y,
    const std::string & format =""
)
```


### function named_plot

```cpp
template <typename NumericX ,
typename NumericY >
bool named_plot(
    const std::string & name,
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & format =""
)
```


### function named_semilogx

```cpp
template <typename NumericX ,
typename NumericY >
bool named_semilogx(
    const std::string & name,
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & format =""
)
```


### function named_semilogy

```cpp
template <typename NumericX ,
typename NumericY >
bool named_semilogy(
    const std::string & name,
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & format =""
)
```


### function named_loglog

```cpp
template <typename NumericX ,
typename NumericY >
bool named_loglog(
    const std::string & name,
    const std::vector< NumericX > & x,
    const std::vector< NumericY > & y,
    const std::string & format =""
)
```


### function plot

```cpp
template <typename Numeric >
bool plot(
    const std::vector< Numeric > & y,
    const std::string & format =""
)
```


### function plot

```cpp
template <typename Numeric >
bool plot(
    const std::vector< Numeric > & y,
    const std::map< std::string, std::string > & keywords
)
```


### function stem

```cpp
template <typename Numeric >
bool stem(
    const std::vector< Numeric > & y,
    const std::string & format =""
)
```


### function text

```cpp
template <typename Numeric >
void text(
    Numeric x,
    Numeric y,
    const std::string & s =""
)
```


### function colorbar

```cpp
inline void colorbar(
    PyObject * mappable =NULL,
    const std::map< std::string, float > & keywords ={}
)
```


### function figure

```cpp
inline long figure(
    long number =-1
)
```


### function fignum_exists

```cpp
inline bool fignum_exists(
    long number
)
```


### function figure_size

```cpp
inline void figure_size(
    size_t w,
    size_t h
)
```


### function legend

```cpp
inline void legend()
```


### function legend

```cpp
inline void legend(
    const std::map< std::string, std::string > & keywords
)
```


### function set_aspect

```cpp
template <typename Numeric >
inline void set_aspect(
    Numeric ratio
)
```


### function set_aspect_equal

```cpp
inline void set_aspect_equal()
```


### function ylim

```cpp
template <typename Numeric >
void ylim(
    Numeric left,
    Numeric right
)
```


### function xlim

```cpp
template <typename Numeric >
void xlim(
    Numeric left,
    Numeric right
)
```


### function xlim

```cpp
inline std::array< double, 2 > xlim()
```


### function ylim

```cpp
inline std::array< double, 2 > ylim()
```


### function xticks

```cpp
template <typename Numeric >
inline void xticks(
    const std::vector< Numeric > & ticks,
    const std::vector< std::string > & labels ={},
    const std::map< std::string, std::string > & keywords ={}
)
```


### function xticks

```cpp
template <typename Numeric >
inline void xticks(
    const std::vector< Numeric > & ticks,
    const std::map< std::string, std::string > & keywords
)
```


### function yticks

```cpp
template <typename Numeric >
inline void yticks(
    const std::vector< Numeric > & ticks,
    const std::vector< std::string > & labels ={},
    const std::map< std::string, std::string > & keywords ={}
)
```


### function yticks

```cpp
template <typename Numeric >
inline void yticks(
    const std::vector< Numeric > & ticks,
    const std::map< std::string, std::string > & keywords
)
```


### function margins

```cpp
template <typename Numeric >
inline void margins(
    Numeric margin
)
```


### function margins

```cpp
template <typename Numeric >
inline void margins(
    Numeric margin_x,
    Numeric margin_y
)
```


### function tick_params

```cpp
inline void tick_params(
    const std::map< std::string, std::string > & keywords,
    const std::string axis ="both"
)
```


### function subplot

```cpp
inline void subplot(
    long nrows,
    long ncols,
    long plot_number
)
```


### function subplot2grid

```cpp
inline void subplot2grid(
    long nrows,
    long ncols,
    long rowid =0,
    long colid =0,
    long rowspan =1,
    long colspan =1
)
```


### function title

```cpp
inline void title(
    const std::string & titlestr,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function suptitle

```cpp
inline void suptitle(
    const std::string & suptitlestr,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function axis

```cpp
inline void axis(
    const std::string & axisstr
)
```


### function axhline

```cpp
inline void axhline(
    double y,
    double xmin =0.,
    double xmax =1.,
    const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >()
)
```


### function axvline

```cpp
inline void axvline(
    double x,
    double ymin =0.,
    double ymax =1.,
    const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >()
)
```


### function axvspan

```cpp
inline void axvspan(
    double xmin,
    double xmax,
    double ymin =0.,
    double ymax =1.,
    const std::map< std::string, std::string > & keywords =std::map< std::string, std::string >()
)
```


### function xlabel

```cpp
inline void xlabel(
    const std::string & str,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function ylabel

```cpp
inline void ylabel(
    const std::string & str,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function set_zlabel

```cpp
inline void set_zlabel(
    const std::string & str,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function grid

```cpp
inline void grid(
    bool flag,
    std::string which ="major",
    std::string axis ="both"
)
```


### function show

```cpp
inline void show(
    const bool block =true
)
```


### function close

```cpp
inline void close()
```


### function xkcd

```cpp
inline void xkcd()
```


### function draw

```cpp
inline void draw()
```


### function pause

```cpp
template <typename Numeric >
inline void pause(
    Numeric interval
)
```


### function save

```cpp
inline void save(
    const std::string & filename,
    const int dpi =0
)
```


### function rcparams

```cpp
inline void rcparams(
    const std::map< std::string, std::string > & keywords ={}
)
```


### function clf

```cpp
inline void clf()
```


### function cla

```cpp
inline void cla()
```


### function ion

```cpp
inline void ion()
```


### function ginput

```cpp
inline std::vector< std::array< double, 2 > > ginput(
    const int numClicks =1,
    const std::map< std::string, std::string > & keywords ={}
)
```


### function tight_layout

```cpp
inline void tight_layout()
```


### function plot

```cpp
template <typename... Args>
bool plot()
```


### function plot

```cpp
template <typename A ,
typename B ,
typename... Args>
bool plot(
    const A & a,
    const B & b,
    const std::string & format,
    Args... args
)
```


### function plot

```cpp
inline bool plot(
    const std::vector< double > & x,
    const std::vector< double > & y,
    const std::string & format =""
)
```


### function plot

```cpp
inline bool plot(
    const std::vector< double > & y,
    const std::string & format =""
)
```


### function plot

```cpp
inline bool plot(
    const std::vector< double > & x,
    const std::vector< double > & y,
    const std::map< std::string, std::string > & keywords
)
```






-------------------------------

Updated on 2022-09-25 at 23:10:54 +0900