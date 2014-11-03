<?php

/* IntegralCoreBundle:Default:index.html.twig */
class __TwigTemplate_32ba6837231cc145730daf7e318f0acff02da2e84375800ec1345d38158ae66a extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        echo "<!DOCTYPE html>
<html>
    <head>
        <title>Integral</title>

        ";
        // line 6
        if (isset($context['assetic']['debug']) && $context['assetic']['debug']) {
            // asset "586e0d6_0"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_586e0d6_0") : $this->env->getExtension('assets')->getAssetUrl("_controller/images/586e0d6_favicon_1.ico");
            // line 7
            echo "        \t<link type = \"image/x-icon\" rel = \"shortcut icon\" href = \"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" />
\t\t";
        } else {
            // asset "586e0d6"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_586e0d6") : $this->env->getExtension('assets')->getAssetUrl("_controller/images/586e0d6.ico");
            echo "        \t<link type = \"image/x-icon\" rel = \"shortcut icon\" href = \"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" />
\t\t";
        }
        unset($context["asset_url"]);
        // line 9
        echo "\t
\t\t";
        // line 10
        if (isset($context['assetic']['debug']) && $context['assetic']['debug']) {
            // asset "e12efce_0"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_e12efce_0") : $this->env->getExtension('assets')->getAssetUrl("_controller/css/e12efce_style_1.css");
            // line 13
            echo "
    \t\t<link rel=\"stylesheet\" href=\"";
            // line 14
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" media=\"screen\" />
\t\t";
            // asset "e12efce_1"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_e12efce_1") : $this->env->getExtension('assets')->getAssetUrl("_controller/css/e12efce_part_2_bootstrap.min_1.css");
            // line 13
            echo "
    \t\t<link rel=\"stylesheet\" href=\"";
            // line 14
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" media=\"screen\" />
\t\t";
            // asset "e12efce_2"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_e12efce_2") : $this->env->getExtension('assets')->getAssetUrl("_controller/css/e12efce_part_2_style_2.css");
            // line 13
            echo "
    \t\t<link rel=\"stylesheet\" href=\"";
            // line 14
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" media=\"screen\" />
\t\t";
        } else {
            // asset "e12efce"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_e12efce") : $this->env->getExtension('assets')->getAssetUrl("_controller/css/e12efce.css");
            // line 13
            echo "
    \t\t<link rel=\"stylesheet\" href=\"";
            // line 14
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" media=\"screen\" />
\t\t";
        }
        unset($context["asset_url"]);
        // line 16
        echo "
\t\t";
        // line 17
        if (isset($context['assetic']['debug']) && $context['assetic']['debug']) {
            // asset "69cdddb_0"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_69cdddb_0") : $this->env->getExtension('assets')->getAssetUrl("_controller/js/69cdddb_jquery-1.11.1.min_1.js");
            // line 21
            echo "
    \t\t<script type=\"text/javascript\" src=\"";
            // line 22
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\"></script>
\t\t";
            // asset "69cdddb_1"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_69cdddb_1") : $this->env->getExtension('assets')->getAssetUrl("_controller/js/69cdddb_bootstrap.min_2.js");
            // line 21
            echo "
    \t\t<script type=\"text/javascript\" src=\"";
            // line 22
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\"></script>
\t\t";
            // asset "69cdddb_2"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_69cdddb_2") : $this->env->getExtension('assets')->getAssetUrl("_controller/js/69cdddb_part_3_script_1.js");
            // line 21
            echo "
    \t\t<script type=\"text/javascript\" src=\"";
            // line 22
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\"></script>
\t\t";
        } else {
            // asset "69cdddb"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_69cdddb") : $this->env->getExtension('assets')->getAssetUrl("_controller/js/69cdddb.js");
            // line 21
            echo "
    \t\t<script type=\"text/javascript\" src=\"";
            // line 22
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\"></script>
\t\t";
        }
        unset($context["asset_url"]);
        // line 24
        echo "    </head>

    <body>
    \t<div class = \"menu\">
\t    \t<div class = \"container\">
\t   \t\t\t<div class = \"row\">
\t   \t\t\t\t<div class = \"col-xs-3 menu-item active-menu-item\">Computate</div>
\t        \t\t<div class = \"col-xs-3 menu-item\">Syntax</div>
\t        \t\t<div class = \"col-xs-3 menu-item\">Help</div>
\t        \t\t<div class = \"col-xs-3 menu-item\">Credits</div>
\t\t   \t\t</div>
\t\t   \t\t<div class = \"row\">
\t\t   \t\t\t<div class = \"col-xs-12\" id = \"gradient-line\"></div>
\t        \t</div>
\t    \t</div>
    \t</div>

    \t<div class = \"slider\">
\t        <div class = \"slide active-slide\">
\t        \t<div class = \"container\">
\t        \t\t<div class = \"row\">

\t        \t\t\t<div class = \"col-xs-1\">
\t\t        \t\t\t<div class = \"dropdown-item active-dropdown-item\" id = \"comp-time\">
\t\t        \t\t\t\t<a>3s</a><span class = \"caret\"></span>
\t\t        \t\t\t</div>
\t\t        \t\t\t<ul class = \"dropdown-items\">
\t\t        \t\t\t\t<li class = \"dropdown-item\">3s</li>
\t\t        \t\t\t\t<li class = \"dropdown-item\">15s</li>
\t\t        \t\t\t\t<li class = \"dropdown-item\">90s</li>
\t\t        \t\t\t</ul>
\t        \t\t\t</div>

\t        \t\t\t<div class = \"col-xs-5\">
\t        \t\t\t\t<input tabindex = \"0\" id = \"upper-domain\"   type = \"text\" maxlength = \"128\">
\t        \t\t\t\t
\t\t\t\t\t        ";
        // line 60
        if (isset($context['assetic']['debug']) && $context['assetic']['debug']) {
            // asset "1c4149b_0"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_1c4149b_0") : $this->env->getExtension('assets')->getAssetUrl("_controller/images/1c4149b_integral-vec_1.png");
            // line 61
            echo "\t\t\t\t\t        \t<img src = \"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" id = \"integral-sign\" width = \"51\" />
\t\t\t\t\t\t\t";
        } else {
            // asset "1c4149b"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_1c4149b") : $this->env->getExtension('assets')->getAssetUrl("_controller/images/1c4149b.png");
            echo "\t\t\t\t\t        \t<img src = \"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" id = \"integral-sign\" width = \"51\" />
\t\t\t\t\t\t\t";
        }
        unset($context["asset_url"]);
        // line 63
        echo "
\t        \t\t\t\t<input tabindex = \"2\" id = \"lower-domain\"   type = \"text\" maxlength = \"128\">
\t        \t\t\t\t<input tabindex = \"1\" id = \"function-input\" type = \"text\" maxlength = \"128\" autofocus>
\t        \t\t\t</div>

\t        \t\t\t<div class = \"col-xs-1\">
\t        \t\t\t\t<div class = \"dropdown-item active-dropdown-item\" id = \"variable\">
\t        \t\t\t\t\t<a>dx</a><span class = \"caret\"></span>
\t        \t\t\t\t</div>
\t        \t\t\t\t<ul class = \"dropdown-items\">
\t        \t\t\t\t\t<li class = \"dropdown-item\">dp</li>
\t        \t\t\t\t\t<li class = \"dropdown-item\">dt</li>
\t        \t\t\t\t\t<li class = \"dropdown-item\">du</li>
\t        \t\t\t\t\t<li class = \"dropdown-item\">dx</li>
\t        \t\t\t\t\t<li class = \"dropdown-item\">dy</li>
\t        \t\t\t\t\t<li class = \"dropdown-item\">dz</li>
\t        \t\t\t\t</ul>
\t        \t\t\t</div>\t

\t        \t\t\t<div class = \"col-xs-1\">
\t        \t\t\t\t<input id = \"comp-button\" type = \"submit\" value = \"=\">
\t        \t\t\t</div>\t

\t        \t\t\t<div class = \"col-xs-4\">

        \t\t\t\t\t<ul id = \"infotable\">
        \t\t\t\t\t\t<li id = \"computationMessage\">&nbsp</li>
        \t\t\t\t\t\t<li id = \"computationValue\">input your data!</li>
        \t\t\t\t\t\t<li id = \"computationEps\">&nbsp</li>
        \t\t\t\t\t</ul>
        \t\t\t\t\t
\t        \t\t\t</div>

\t        \t\t</div>

\t        \t</div>
\t        </div>

\t        <div class = \"slide\" id = \"syntax\">
\t        \t<div class = \"container\">
\t        \t\t<div class = \"row\">
\t\t\t\t\t\t
\t        \t\t\t<div class = \"col-xs-4 syntax-first\">
\t        \t\t\t\t<h2>operations</h2>
\t        \t\t\t\t<p><code>+ - * / ^</code></p>
\t        \t\t\t</div>

\t        \t\t\t<div class = \"col-xs-4 syntax-first\">
\t        \t\t\t\t<h2>constants</h2>
\t        \t\t\t\t<p><code>e pi</code></p>
\t        \t\t\t</div>
\t        \t\t\t<div class = \"col-xs-4 syntax-first\">
\t\t\t\t\t\t\t<h2>delimiters</h2>
        \t\t\t\t\t<p><code>, ;</code></p>
\t        \t\t\t</div>

\t\t\t\t\t\t<div class = \"col-xs-4\">
\t\t\t\t\t\t\t
\t\t\t\t\t\t\t<h2>functions</h2>
\t\t\t\t\t\t\t<ul>
\t\t\t\t\t\t\t\t<li><b><code>sin x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>cos x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>tg x&nbsp</code></b> or <b><code>tan x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>ctg x</code></b> or <b><code>cot x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>sec x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>cosec x</code></b> or <b><code>csc x</code></b></li><br>
\t\t\t\t\t\t\t\t<li><b><code>arcsin x</code></b> or <b><code>asin x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>arccos x</code></b> or <b><code>acos x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>arctg x&nbsp</code></b> or <b><code>arctan x</code></b> or <b><code>atan x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>arcctg x</code></b> or <b><code>arccot x</code></b> or <b><code>acot x</code></b></li><br>
\t\t\t\t\t\t\t\t<li><b><code>sh x&nbsp</code></b> or <b><code>sinh x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>ch x&nbsp</code></b> or <b><code>cosh x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>th x&nbsp</code></b> or <b><code>tanh x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>cth x</code></b> or <b><code>coth x</code></b></li>
\t\t\t\t\t\t\t</ul>
\t\t\t\t\t\t</div>\t        \t\t\t     \t\t\t

\t\t\t\t\t\t<div class = \"col-xs-4\">
\t\t\t\t\t\t\t
\t\t\t\t\t\t\t<h2>functions</h2>
\t\t\t\t\t\t\t<ul>
\t\t\t\t\t\t\t\t<li><b><code>arsh x&nbsp</code></b> or <b><code>arsinh x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>arch x&nbsp</code></b> or <b><code>arcosh x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>arth x&nbsp</code></b> or <b><code>artanh x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>arcth x</code></b> or <b><code>arcoth x</code></b></li><br>
\t\t\t\t\t\t\t\t<li><b><code>exp x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>ln x</code></b> or <b><code>log x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>sqrt x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>cbrt x</code></b> <code style = \"color: black\">//</code> cubic root (<b>x</b> is any)</li>
\t\t\t\t\t\t\t\t<li><b><code>abs x</code></b> or <b><code>|x|</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>floor x</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>sign x</code></b> or <b><code>sgn x</code></b></li><br>
\t\t\t\t\t\t\t\t<li><b><code>min (x, y)</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>max (x, y)</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>pow (x, y) = x ^ y</code></b></li>
\t\t\t\t\t\t\t</ul>
\t\t\t\t\t\t</div>

\t\t\t\t\t\t<div class = \"col-xs-4\">
\t\t\t\t\t\t\t
        \t\t\t\t\t<h2>functions</h2>
\t\t\t\t\t\t\t<ul>
\t\t\t\t\t\t\t\t<li><b><code>gamma x</code></b> <code style = \"color: black\">//</code> Euler's gamma function</li>
\t\t\t\t\t\t\t\t<li><b><code>lgamma x = ln (gamma x)</code></b></li>
\t\t\t\t\t\t\t\t<li><b><code>erf x</code></b> <code style = \"color: black\">//</code> error function</li>
\t\t\t\t\t\t\t\t<li><b><code>bessel_j (n; x)</code></b> <code style = \"color: black\">//</code> Bessel's function of the first kind, <b>n</b> is integer</li>
\t\t\t\t\t\t\t\t<li><b><code>jO x</code></b> or <b><code>j_O x</code></b> <code style = \"color: black\">//</code> Bessel's function of the first kind with <b>n = 0</b></li>
\t\t\t\t\t\t\t\t<li><b><code>bessel_y (n; x)</code></b> <code style = \"color: black\">//</code> Bessel's function of the second kind, <b>n</b> is integer, &nbsp<b>x > 0</b></li>
\t\t\t\t\t\t\t\t<li><b><code>yO x</code></b> or <b><code>y_O x</code></b> <code style = \"color: black\">//</code> Bessel's function of the second kind with <b>n = 0</b>, <b>x > 0</b></li>
\t\t\t\t\t\t\t</ul>
\t\t\t\t\t\t</div>
\t        \t\t</div>
\t        \t</div>
\t        </div>

\t        <div class = \"slide\" id = \"help\">
\t        \t<div class = \"container\">
\t        \t\t<div class = \"row\">
\t        \t\t\t<div class = \"col-xs-1\"></div>\t        \t\t\t
\t        \t\t\t<div class = \"col-xs-10\">
\t\t        \t\t\t<ul>
\t\t        \t\t\t\t<li>Use <b><code>inf</code></b> or <b><code>oo</code></b> (<b><code>+</code></b> or <b><code>-</code></b>) for infinite domains</li>
\t\t\t\t\t\t\t\t<li>You can use both <b><code>()</code></b> and <b><code>[]</code></b> brackets</li>
\t\t\t\t\t\t\t\t<li>You can omit brackets and <b><code>*</code></b> mark if it is possible (e.g. <b><code>3exp-x</code></b>)</li>
\t\t\t\t\t\t\t</ul>
\t\t\t\t\t\t\t<ul>\t
\t\t\t\t\t\t\t\t<li>Hit <b><code>C</code></b> or integral sign to clear all input fields</li>
\t\t\t\t\t\t\t\t<li>Hit <b><code>Enter</code></b> in order to computate integral</li>
\t\t\t\t\t\t\t\t<li>Switch between navigation bar items using arrow keys</li>
\t\t\t\t\t\t\t\t<li>Switch between input fields using <b><code>Tab</code></b></li>
\t\t\t\t\t\t\t</ul>
\t\t\t\t\t\t\t<ul>
\t\t\t\t\t\t\t\t<li>If you are trying to computate improper integral, make sure it is convergent</li>
\t\t        \t\t\t\t<li>More detailed computation information is available in browser console</li>
\t\t        \t\t\t</ul>
\t        \t\t\t</div>
\t        \t\t</div>
\t        \t</div>
\t        </div>

\t        <div class = \"slide\">
\t        \t<div class = \"container\">
\t        \t\t<div class = \"row\">
\t        \t\t\t<div class = \"col-xs-1\"></div>
\t        \t\t\t<div class = \"col-xs-10\" id = \"credits\">
\t        \t\t\t\t<ul>
\t        \t\t\t\t\t<li>Gaussian Quadrature Integral &mdash; created and designed by Yell Bond (<a href = \"https://github.com/monstaHD/Gaussian_Quadrature_Web\" target = \"_blank\">Github</a>).</li>
\t        \t\t\t\t\t<li>I hope this program will be useful for you, <b>but without any warranty!</b></li>
\t        \t\t\t\t\t<li>Feel free to write me an email, if you want: <a href = \"mailto: yell.bondarenko@gmail.com\"><em>yell.bondarenko@gmail.com</em></a></li>
\t        \t\t\t\t</ul>
\t        \t\t\t</div>
\t        \t\t</div>
\t        \t</div>
\t        </div>
        </div>
    </body>
</html>\t";
    }

    public function getTemplateName()
    {
        return "IntegralCoreBundle:Default:index.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  188 => 63,  174 => 61,  170 => 60,  132 => 24,  126 => 22,  123 => 21,  116 => 22,  113 => 21,  107 => 22,  104 => 21,  98 => 22,  95 => 21,  91 => 17,  88 => 16,  82 => 14,  79 => 13,  72 => 14,  69 => 13,  63 => 14,  60 => 13,  54 => 14,  51 => 13,  47 => 10,  44 => 9,  30 => 7,  26 => 6,  19 => 1,);
    }
}
