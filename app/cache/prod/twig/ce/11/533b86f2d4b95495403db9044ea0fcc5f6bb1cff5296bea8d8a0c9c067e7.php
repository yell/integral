<?php

/* TwigBundle:Exception:traces_text.html.twig */
class __TwigTemplate_ce11533b86f2d4b95495403db9044ea0fcc5f6bb1cff5296bea8d8a0c9c067e7 extends Twig_Template
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
        echo "<div class=\"block\">
    <h2>
        Stack Trace (Plain Text)&nbsp;
        ";
        // line 4
        ob_start();
        // line 5
        echo "        <a href=\"#\" onclick=\"toggle('traces-text'); switchIcons('icon-traces-text-open', 'icon-traces-text-close'); return false;\">
            <img class=\"toggle\" id=\"icon-traces-text-close\" alt=\"-\" src=\"data:image/gif;base64,R0lGODlhEgASAMQSANft94TG57Hb8GS44ez1+mC24IvK6ePx+Wa44dXs92+942e54o3L6W2844/M6dnu+P/+/l614P///wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAEAABIALAAAAAASABIAQAVCoCQBTBOd6Kk4gJhGBCTPxysJb44K0qD/ER/wlxjmisZkMqBEBW5NHrMZmVKvv9hMVsO+hE0EoNAstEYGxG9heIhCADs=\" style=\"display: none\" />
            <img class=\"toggle\" id=\"icon-traces-text-open\" alt=\"+\" src=\"data:image/gif;base64,R0lGODlhEgASAMQTANft99/v+Ga44bHb8ITG52S44dXs9+z1+uPx+YvK6WC24G+944/M6W28443L6dnu+Ge54v/+/l614P///wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAEAABMALAAAAAASABIAQAVS4DQBTiOd6LkwgJgeUSzHSDoNaZ4PU6FLgYBA5/vFID/DbylRGiNIZu74I0h1hNsVxbNuUV4d9SsZM2EzWe1qThVzwWFOAFCQFa1RQq6DJB4iIQA7\" style=\"display: inline\" />
        </a>
        ";
        echo trim(preg_replace('/>\s+</', '><', ob_get_clean()));
        // line 10
        echo "    </h2>

    <div id=\"traces-text\" class=\"trace\" style=\"display: none;\">
<pre>";
        // line 13
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["exception"]) ? $context["exception"] : null), "toarray"));
        foreach ($context['_seq'] as $context["i"] => $context["e"]) {
            // line 14
            echo "[";
            echo twig_escape_filter($this->env, ((isset($context["i"]) ? $context["i"] : null) + 1), "html", null, true);
            echo "] ";
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["e"]) ? $context["e"] : null), "class"), "html", null, true);
            echo ": ";
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["e"]) ? $context["e"] : null), "message"), "html", null, true);
            echo "
";
            // line 15
            $this->env->loadTemplate("TwigBundle:Exception:traces.txt.twig")->display(array("exception" => (isset($context["e"]) ? $context["e"] : null)));
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['i'], $context['e'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 16
        echo "</pre>
    </div>
</div>
";
    }

    public function getTemplateName()
    {
        return "TwigBundle:Exception:traces_text.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  38 => 13,  98 => 40,  93 => 9,  88 => 6,  78 => 40,  44 => 9,  43 => 8,  40 => 8,  46 => 10,  26 => 5,  201 => 92,  196 => 90,  183 => 82,  171 => 73,  166 => 71,  163 => 70,  158 => 67,  156 => 66,  151 => 63,  142 => 59,  138 => 57,  136 => 56,  123 => 47,  121 => 46,  117 => 44,  115 => 43,  105 => 40,  101 => 39,  91 => 31,  69 => 25,  66 => 24,  62 => 23,  49 => 19,  27 => 4,  24 => 4,  22 => 1,  32 => 6,  25 => 3,  35 => 4,  29 => 4,  21 => 2,  19 => 1,  209 => 82,  203 => 78,  199 => 91,  193 => 73,  189 => 71,  187 => 84,  182 => 68,  176 => 64,  173 => 74,  168 => 72,  164 => 60,  162 => 59,  154 => 54,  149 => 51,  147 => 50,  144 => 49,  141 => 48,  133 => 55,  130 => 41,  125 => 38,  122 => 37,  116 => 36,  112 => 42,  109 => 34,  106 => 33,  103 => 32,  99 => 30,  95 => 28,  92 => 27,  86 => 28,  82 => 22,  80 => 41,  73 => 19,  64 => 15,  60 => 13,  57 => 16,  54 => 11,  51 => 15,  48 => 9,  45 => 8,  42 => 14,  39 => 16,  36 => 7,  33 => 10,  30 => 3,);
    }
}
