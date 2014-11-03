<?php

/* IntegralCoreBundle:Default:calc.html.twig */
class __TwigTemplate_35b5f7bfa7d185b5fada7f66bf78713b947e0cccb09cb43303acb09582612477 extends Twig_Template
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
        echo twig_escape_filter($this->env, (isset($context["integratingFunction"]) ? $context["integratingFunction"] : $this->getContext($context, "integratingFunction")), "html", null, true);
    }

    public function getTemplateName()
    {
        return "IntegralCoreBundle:Default:calc.html.twig";
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
