<?php

/* IntegralCoreBundle:Default:getpage.html.twig */
class __TwigTemplate_f153c7df27eeb301f3afa57c39d263c87a292a7e1d7849d490372f16103106c0 extends Twig_Template
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
        echo "<pre>";
        echo twig_escape_filter($this->env, (isset($context["output"]) ? $context["output"] : $this->getContext($context, "output")), "html", null, true);
        echo "</pre>";
    }

    public function getTemplateName()
    {
        return "IntegralCoreBundle:Default:getpage.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  19 => 1,);
    }
}
