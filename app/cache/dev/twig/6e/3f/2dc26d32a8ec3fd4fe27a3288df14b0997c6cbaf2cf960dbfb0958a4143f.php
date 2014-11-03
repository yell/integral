<?php

/* IntegralCoreBundle:Default:run.html.twig */
class __TwigTemplate_6e3f2dc26d32a8ec3fd4fe27a3288df14b0997c6cbaf2cf960dbfb0958a4143f extends Twig_Template
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
        echo twig_escape_filter($this->env, (isset($context["integralreply"]) ? $context["integralreply"] : $this->getContext($context, "integralreply")), "html", null, true);
    }

    public function getTemplateName()
    {
        return "IntegralCoreBundle:Default:run.html.twig";
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
