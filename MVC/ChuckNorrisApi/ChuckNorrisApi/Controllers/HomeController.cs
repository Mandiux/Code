using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
using System.Net;
using System.Web.Mvc;
using Newtonsoft.Json;
using ChuckNorrisApi.Models;

namespace ChuckNorrisApi.Controllers
{
    public class HomeController : Controller
    {
        [HttpGet]
        public ActionResult Index()
        {
            Chuck chuck = new Chuck();

            return View(chuck);
        }

        [HttpPost]
        public ActionResult Index(Chuck chuck)
        {
            chuck.getJoke();
            return View(chuck);
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}