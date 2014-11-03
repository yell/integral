<?php

namespace Integral\CoreBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Request;

class DefaultController extends Controller
{
    public function indexAction()
    {
        return $this->render('IntegralCoreBundle:Default:index.html.twig');
    }

    public function runEngine($integratingFunction, $lowerDomain, $upperDomain, $currentVariable, $computationTime)
    {

        // Call to C bin file goes here...

        $descriptorspec = array(
           0 => array("pipe", "r"),  // stdin - канал, из которого дочерний процесс будет читать
           1 => array("pipe", "w"),  // stdout - канал, в который дочерний процесс будет записывать 
           2 => array("file", "/tmp/integral-engine.log", "a") // stderr - файл для записи
        );

        $cwd = '/tmp';
        $env = array('some_option' => '');

        $process = proc_open('/var/www/Dropbox/Integral/engine/integral-engine', $descriptorspec, $pipes, $cwd, $env);

        if (is_resource($process)) {
            // $pipes теперь выглядит так:
            // 0 => записывающий обработчик, подключенный к дочернему stdin
            // 1 => читающий обработчик, подключенный к дочернему stdout
            // Вывод сообщений об ошибках будет добавляться в /tmp/error-output.txt

            $requestStr = '["'.$integratingFunction.'", "'.$lowerDomain.'", "'.$upperDomain.'", "'.$currentVariable.'", '.$computationTime.']';

            fwrite($pipes[0], $requestStr);
            fclose($pipes[0]);            

            $integralreply = stream_get_contents($pipes[1]);
            // var_dump($integralreply);
            fclose($pipes[1]);

            // Важно закрывать все каналы перед вызовом
            // proc_close во избежание мертвой блокировки
            $return_value = proc_close($process);

        }

        return $integralreply;
    }

    public function calcAction()
    {
        $request = Request::createFromGlobals();
        $inputData = $request->request->get('inputData');
        $outputData = $this->runEngine($inputData[0],
                                       $inputData[1], $inputData[2],
                                       $inputData[3], $inputData[4]);
        return $this->render('IntegralCoreBundle:Default:calc.html.twig',
                        array ("integratingFunction" => $outputData));
    }
}